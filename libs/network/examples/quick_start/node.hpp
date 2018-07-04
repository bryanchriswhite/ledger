#ifndef QUICK_START_NODE_HPP
#define QUICK_START_NODE_HPP

#include"network/service/client.hpp"
#include"./protocols/quick_start/protocol.hpp" // defines our quick start protocol

namespace fetch
{
namespace quick_start
{

using clientType = service::ServiceClient<network::TCPClient>;

// Custom class we want to pass using the RPC interface
class DataClass
{
public:
  std::vector<int> data_;
};

class Node
{
public:
  Node(fetch::network::ThreadManager tm) : tm_{tm} {}
  ~Node() {}

  void sendMessage(std::string const &msg, uint16_t port)
  {
    std::cout << "\nNode sending: \"" << msg << "\" to: " << port <<  std::endl;

    clientType client{"localhost", port, tm_};

    for (std::size_t i = 0; ; ++i)
    {
      if(client.is_alive()) break;
      std::cout << "Waiting for client to connect..." << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(10));

      if(i == 10)
      {
        std::cout << "Failed to connect to client" << std::endl;
        return;
      }
    }

    // Ping the client
    client.Call(protocols::FetchProtocols::QUICK_START,
                    protocols::QuickStart::PING);

    // Call the SEND_MESSAGE function using the QUICK_START protocol
    // sending msg, and getting result (calls receiveMessage)
    int result = client.Call(protocols::FetchProtocols::QUICK_START,
                                 protocols::QuickStart::SEND_MESSAGE,
                                 msg).As<int>();

    std::cout << "Remote responded: " << result << std::endl;

    // Send data using our custom class
    DataClass d;
    d.data_ = {1,2,3};
    auto prom = client.Call(protocols::FetchProtocols::QUICK_START,
                    protocols::QuickStart::SEND_DATA, d);

    prom.Wait();
  }

  ////////////////////////////////////////////
  // Functions exposed via RPC

  // This is called when nodes are calling SEND_MESSAGE on us
  int receiveMessage(std::string const &msg)
  {
    std::cout << "Node received: " << msg << std::endl;
    static int count{0};
    return count++;
  }

  void receiveData(DataClass const &data)
  {
    std::cout << "Received data:" << std::endl;
    for(auto &i : data.data_)
    {
      std::cout << i << std::endl;
    }
  }

  void ping()
  {
    std::cout << "We have been pinged!" << std::endl;
  }

private:
  fetch::network::ThreadManager tm_;
};

// All classes and data types must have an associated Serialize and Deserialize function
// So we define one for our class (vector already has a ser/deser)
template <typename T>
inline void Serialize(T &serializer, DataClass const &data) {
  serializer << data.data_;
}

template <typename T>
inline void Deserialize(T &serializer, DataClass &data) {
  serializer >> data.data_;
}

} // namespace quick_start
} // namespace fetch
#endif
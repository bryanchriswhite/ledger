#include<gtest/gtest.h>

#include"math/linalg/prototype.hpp"
#include"math/linalg/matrix.hpp"
#include"math/linalg/blas/base.hpp"
#include"math/linalg/blas/gemm_tn_novector.hpp"
#include"math/linalg/blas/gemm_tn_novector_threaded.hpp"


using namespace fetch;
using namespace fetch::math::linalg;

TEST(blas_DGEMM, blas_gemm_tn_novector1) {

	Blas< double, 
        Signature( _C <= _alpha, _A, _B, _beta, _C ), 
        Computes( _C = _alpha * T(_A) * _B + _beta * _C ), 
        platform::Parallelisation::NOT_PARALLEL> gemm_tn_novector;
	// Compuing _C = _alpha * T(_A) * _B + _beta * _C
  using type = double;  

  type alpha = type(1);
  type beta = type(0);

Matrix< type > A = Matrix< type >(R"(
	0.3745401188473625 0.9507143064099162 0.7319939418114051;
 0.5986584841970366 0.15601864044243652 0.15599452033620265
	)");

Matrix< type > B = Matrix< type >(R"(
	0.05808361216819946 0.8661761457749352 0.6011150117432088;
 0.7080725777960455 0.020584494295802447 0.9699098521619943
	)");

Matrix< type > C = Matrix< type >(R"(
	0.8324426408004217 0.21233911067827616 0.18182496720710062;
 0.18340450985343382 0.3042422429595377 0.5247564316322378;
 0.43194501864211576 0.2912291401980419 0.6118528947223795
	)");

  Matrix< type > R = Matrix< type >(R"(
	0.4456482991294304 0.33674079873438223 0.8057864498423064;
 0.1656934419785827 0.8266976184734581 0.7228126579480724;
 0.15297229436215787 0.6372467595628419 0.591313169085288
	)");
  
	gemm_tn_novector(alpha, A, B, beta, C);



	ASSERT_TRUE( R.AllClose(C) );
   
}

TEST(blas_DGEMM, blas_gemm_tn_novector2) {

	Blas< double, 
        Signature( _C <= _alpha, _A, _B, _beta, _C ), 
        Computes( _C = _alpha * T(_A) * _B + _beta * _C ), 
        platform::Parallelisation::NOT_PARALLEL> gemm_tn_novector;
	// Compuing _C = _alpha * T(_A) * _B + _beta * _C
  using type = double;  

  type alpha = type(0);
  type beta = type(1);

Matrix< type > A = Matrix< type >(R"(
	0.13949386065204183 0.29214464853521815 0.3663618432936917;
 0.45606998421703593 0.7851759613930136 0.19967378215835974
	)");

Matrix< type > B = Matrix< type >(R"(
	0.5142344384136116 0.5924145688620425 0.046450412719997725;
 0.6075448519014384 0.17052412368729153 0.06505159298527952
	)");

Matrix< type > C = Matrix< type >(R"(
	0.9488855372533332 0.9656320330745594 0.8083973481164611;
 0.3046137691733707 0.09767211400638387 0.6842330265121569;
 0.4401524937396013 0.12203823484477883 0.4951769101112702
	)");

  Matrix< type > R = Matrix< type >(R"(
	0.9488855372533332 0.9656320330745594 0.8083973481164611;
 0.3046137691733707 0.09767211400638387 0.6842330265121569;
 0.4401524937396013 0.12203823484477883 0.4951769101112702
	)");
  
	gemm_tn_novector(alpha, A, B, beta, C);



	ASSERT_TRUE( R.AllClose(C) );
   
}

TEST(blas_DGEMM, blas_gemm_tn_novector3) {

	Blas< double, 
        Signature( _C <= _alpha, _A, _B, _beta, _C ), 
        Computes( _C = _alpha * T(_A) * _B + _beta * _C ), 
        platform::Parallelisation::NOT_PARALLEL> gemm_tn_novector;
	// Compuing _C = _alpha * T(_A) * _B + _beta * _C
  using type = double;  

  type alpha = type(1);
  type beta = type(1);

Matrix< type > A = Matrix< type >(R"(
	0.034388521115218396 0.9093204020787821 0.2587799816000169;
 0.662522284353982 0.31171107608941095 0.5200680211778108
	)");

Matrix< type > B = Matrix< type >(R"(
	0.5467102793432796 0.18485445552552704 0.9695846277645586;
 0.7751328233611146 0.9394989415641891 0.8948273504276488
	)");

Matrix< type > C = Matrix< type >(R"(
	0.5978999788110851 0.9218742350231168 0.0884925020519195;
 0.1959828624191452 0.045227288910538066 0.32533033076326434;
 0.388677289689482 0.2713490317738959 0.8287375091519293
	)");

  Matrix< type > R = Matrix< type >(R"(
	1.1302433056071457 1.5506700912834535 0.7146781438045392;
 0.9347351599342958 0.5061714427949007 1.4859210106475778;
 0.9332767593138604 0.8077890198114085 1.545017690717192
	)");
  
	gemm_tn_novector(alpha, A, B, beta, C);



	ASSERT_TRUE( R.AllClose(C) );
   
}

TEST(blas_DGEMM, blas_gemm_tn_novector4) {

	Blas< double, 
        Signature( _C <= _alpha, _A, _B, _beta, _C ), 
        Computes( _C = _alpha * T(_A) * _B + _beta * _C ), 
        platform::Parallelisation::NOT_PARALLEL> gemm_tn_novector;
	// Compuing _C = _alpha * T(_A) * _B + _beta * _C
  using type = double;  

  type alpha = type(0.8623256764293328);
  type beta = type(0.2949011823325911);

Matrix< type > A = Matrix< type >(R"(
	0.3567533266935893 0.28093450968738076 0.5426960831582485;
 0.14092422497476265 0.8021969807540397 0.07455064367977082
	)");

Matrix< type > B = Matrix< type >(R"(
	0.9868869366005173 0.7722447692966574 0.1987156815341724;
 0.005522117123602399 0.8154614284548342 0.7068573438476171
	)");

Matrix< type > C = Matrix< type >(R"(
	0.7290071680409873 0.7712703466859457 0.07404465173409036;
 0.3584657285442726 0.11586905952512971 0.8631034258755935;
 0.6232981268275579 0.3308980248526492 0.06355835028602363
	)");

  Matrix< type > R = Matrix< type >(R"(
	0.5192596207039919 0.564117003606653 0.1688673879412895;
 0.3486122287623911 0.7853512199865674 0.7916426338991773;
 0.6460104600650345 0.5114014334374472 0.157180241287307
	)");
  
	gemm_tn_novector(alpha, A, B, beta, C);



	ASSERT_TRUE( R.AllClose(C) );
   
}

TEST(blas_DGEMM, blas_gemm_tn_novector5) {

	Blas< double, 
        Signature( _C <= _alpha, _A, _B, _beta, _C ), 
        Computes( _C = _alpha * T(_A) * _B + _beta * _C ), 
        platform::Parallelisation::NOT_PARALLEL> gemm_tn_novector;
	// Compuing _C = _alpha * T(_A) * _B + _beta * _C
  using type = double;  

  type alpha = type(0.9332167234845005);
  type beta = type(0.8809867285828407);

Matrix< type > A = Matrix< type >(R"(
	0.3109823217156622 0.32518332202674705 0.7296061783380641 0.6375574713552131 0.8872127425763265;
 0.4722149251619493 0.1195942459383017 0.713244787222995 0.7607850486168974 0.5612771975694962;
 0.770967179954561 0.49379559636439074 0.5227328293819941 0.42754101835854963 0.02541912674409519
	)");

Matrix< type > B = Matrix< type >(R"(
	0.10789142699330445 0.03142918568673425 0.6364104112637804 0.3143559810763267 0.5085706911647028;
 0.907566473926093 0.24929222914887494 0.41038292303562973 0.7555511385430487 0.22879816549162246;
 0.07697990982879299 0.289751452913768 0.16122128725400442 0.9296976523425731 0.808120379564417
	)");

Matrix< type > C = Matrix< type >(R"(
	0.6334037565104235 0.8714605901877177 0.8036720768991145 0.18657005888603584 0.8925589984899778;
 0.5393422419156507 0.8074401551640625 0.8960912999234932 0.3180034749718639 0.11005192452767676;
 0.22793516254194168 0.4271077886262563 0.8180147659224931 0.8607305832563434 0.006952130531190703;
 0.5107473025775657 0.417411003148779 0.22210781047073025 0.1198653673336828 0.33761517140362796;
 0.9429097039125192 0.32320293202075523 0.5187906217433661 0.7030189588951778 0.363629602379294
	)");

  Matrix< type > R = Matrix< type >(R"(
	1.0446627237287105 1.095194438246276 1.1895620698881202 1.2574500105667101 1.6161794523108768;
 0.6446596338166107 0.8822273858287794 1.1026692635641566 0.8883001151235388 0.6492206832908973;
 0.9159087166927493 0.7049551374152611 1.5057829488126266 1.9287629287713037 0.898911215267673;
 1.1892204758438063 0.679032576988742 0.9300130509421769 1.199997883057458 1.0848957072323053;
 1.3972242038706133 0.44821060391937584 1.2027513739665507 1.2974315794916524 0.880442752775763
	)");
  
	gemm_tn_novector(alpha, A, B, beta, C);



	ASSERT_TRUE( R.AllClose(C) );
   
}

TEST(blas_DGEMM, blas_gemm_tn_novector6) {

	Blas< double, 
        Signature( _C <= _alpha, _A, _B, _beta, _C ), 
        Computes( _C = _alpha * T(_A) * _B + _beta * _C ), 
        platform::Parallelisation::NOT_PARALLEL> gemm_tn_novector;
	// Compuing _C = _alpha * T(_A) * _B + _beta * _C
  using type = double;  

  type alpha = type(4.193537870982826);
  type beta = type(-1.6264471884210163);

Matrix< type > A = Matrix< type >(R"(
	0.9717820827209607 0.9624472949421112 0.25178229582536416;
 0.49724850589238545 0.30087830981676966 0.2848404943774676
	)");

Matrix< type > B = Matrix< type >(R"(
	0.036886947354532795 0.6095643339798968 0.5026790232288615;
 0.05147875124998935 0.27864646423661144 0.9082658859666537
	)");

Matrix< type > C = Matrix< type >(R"(
	0.23956189066697242 0.1448948720912231 0.489452760277563;
 0.9856504541106007 0.2420552715115004 0.6721355474058786;
 0.7616196153287176 0.23763754399239967 0.7282163486118596
	)");

  Matrix< type > R = Matrix< type >(R"(
	-0.1319678333215149 2.8294778331772976 3.146394659776859;
 -1.389277471632014 2.418128278142431 2.0816488800328203;
 -1.1382958589597834 0.5899490725780501 0.4312665068248305
	)");
  
	gemm_tn_novector(alpha, A, B, beta, C);



	ASSERT_TRUE( R.AllClose(C) );
   
}

TEST(blas_DGEMM, blas_gemm_tn_novector7) {

	Blas< double, 
        Signature( _C <= _alpha, _A, _B, _beta, _C ), 
        Computes( _C = _alpha * T(_A) * _B + _beta * _C ), 
        platform::Parallelisation::NOT_PARALLEL> gemm_tn_novector;
	// Compuing _C = _alpha * T(_A) * _B + _beta * _C
  using type = double;  

  type alpha = type(7.180522091653684);
  type beta = type(-2.794644569327742);

Matrix< type > A = Matrix< type >(R"(
	0.3677831327192532 0.6323058305935795 0.6335297107608947 0.5357746840747585 0.0902897700544083 0.835302495589238 0.32078006497173583 0.18651851039985423 0.040775141554763916 0.5908929431882418;
 0.6775643618422824 0.016587828927856152 0.512093058299281 0.22649577519793795 0.6451727904094499 0.17436642900499144 0.690937738102466 0.3867353463005374 0.9367299887367345 0.13752094414599325;
 0.3410663510502585 0.11347352124058907 0.9246936182785628 0.877339353380981 0.2579416277151556 0.659984046034179 0.8172222002012158 0.5552008115994623 0.5296505783560065 0.24185229090045168;
 0.09310276780589921 0.8972157579533268 0.9004180571633305 0.6331014572732679 0.3390297910487007 0.3492095746126609 0.7259556788702394 0.8971102599525771 0.8870864242651173 0.7798755458576239;
 0.6420316461542878 0.08413996499504883 0.16162871409461377 0.8985541885270792 0.6064290596595899 0.009197051616629648 0.1014715428660321 0.6635017691080558 0.005061583846218687 0.16080805141749865;
 0.5487337893665861 0.6918951976926933 0.6519612595026005 0.22426930946055978 0.7121792213475359 0.23724908749680007 0.3253996981592677 0.7464914051180241 0.6496328990472147 0.8492234104941779;
 0.6576128923003434 0.5683086033354716 0.09367476782809248 0.3677158030594335 0.26520236768172545 0.24398964337908358 0.9730105547524456 0.3930977246667604 0.8920465551771133 0.6311386259972629;
 0.7948113035416484 0.5026370931051921 0.5769038846263591 0.4925176938188639 0.1952429877980445 0.7224521152615053 0.2807723624408558 0.02431596643145384 0.6454722959071678 0.17711067940704894;
 0.9404585843529143 0.9539285770025874 0.9148643902204485 0.3701587002554444 0.015456616528867428 0.9283185625877254 0.42818414831731433 0.9666548190436696 0.9636199770892528 0.8530094554673601;
 0.2944488920695857 0.38509772860192526 0.8511366715168569 0.31692200515627766 0.1694927466860925 0.5568012624583502 0.936154774160781 0.696029796674973 0.570061170089365 0.09717649377076854
	)");

Matrix< type > B = Matrix< type >(R"(
	0.6150072266991697 0.9900538501042633 0.14008401523652403 0.5183296523637367 0.8773730719279554 0.7407686177542044 0.697015740995268 0.7024840839871093 0.35949115121975517 0.29359184426449336;
 0.8093611554785136 0.8101133946791808 0.8670723185801037 0.9132405525564713 0.5113423988609378 0.5015162946871996 0.7982951789667752 0.6499639307777652 0.7019668772577033 0.795792669436101;
 0.8900053418175663 0.3379951568515358 0.375582952639944 0.093981939840869 0.578280140996174 0.035942273796742086 0.46559801813246016 0.5426446347075766 0.2865412521282844 0.5908332605690108;
 0.03050024993904943 0.03734818874921442 0.8226005606596583 0.3601906414112629 0.12706051265188478 0.5222432600548044 0.7699935530986108 0.21582102749684318 0.6228904758190003 0.085347464993768;
 0.0516817211686077 0.531354631568148 0.5406351216101065 0.6374299014982066 0.7260913337226615 0.9758520794625346 0.5163003483011953 0.32295647294124596 0.7951861947687037 0.2708322512620742;
 0.4389714207056361 0.07845638134226596 0.02535074341545751 0.9626484146779251 0.8359801205122058 0.695974206093698 0.4089529444142699 0.17329432007084578 0.15643704267108605 0.25024289816459533;
 0.5492266647061205 0.7145959227000623 0.6601973767177313 0.27993389694594284 0.9548652806631941 0.7378969166957685 0.5543540525114007 0.6117207462343522 0.4196000624277899 0.24773098950115746;
 0.3559726786512616 0.7578461104643691 0.014393488629755868 0.11607264050691624 0.04600264202175275 0.040728802318970136 0.8554605840110072 0.7036578593800237 0.4741738290873252 0.09783416065100148;
 0.49161587511683236 0.4734717707805657 0.17320186991001518 0.43385164923797304 0.39850473439737344 0.6158500980522165 0.6350936508676438 0.04530400977204452 0.3746126146264712 0.6258599157142364;
 0.5031362585800877 0.8564898411883223 0.658693631618945 0.1629344270814297 0.07056874740042984 0.6424192782063156 0.026511310541621813 0.5857755812734633 0.9402302414249576 0.575474177875879
	)");

Matrix< type > C = Matrix< type >(R"(
	0.3881699262065219 0.6432882184423532 0.45825289049151663 0.5456167893159349 0.9414648087765252 0.38610263780077425 0.9611905638239142 0.9053506419560637 0.19579113478929644 0.06936130087516545;
 0.10077800137742665 0.018221825651549728 0.0944429607559284 0.6830067734163568 0.07118864846022899 0.3189756302937613 0.8448753109694546 0.023271935735825866 0.8144684825889358 0.28185477477339993;
 0.11816482762165625 0.6967371653641506 0.628942846779884 0.877472013527053 0.7350710438038858 0.8034809303848486 0.2820345725713065 0.17743954377972282 0.7506147516408583 0.806834739267264;
 0.9905051420006733 0.4126176769114265 0.37201808579278317 0.7764129607419968 0.34080354025301784 0.9307573256035647 0.8584127518430118 0.42899402737501835 0.7508710677914974 0.7545428740846823;
 0.10312386883593261 0.9025529066795667 0.5052523724478571 0.8264574661077416 0.32004960103061175 0.8955232284962005 0.3892016787341631 0.01083765148029836 0.9053819764192637 0.09128667678613356;
 0.31931363759041487 0.9500619670508049 0.9506071469375561 0.5734378881232861 0.6318372121697993 0.44844552197831977 0.29321077169806453 0.32866454536991596 0.6725184560770384 0.75237452943768;
 0.7915790437258485 0.7896181427945539 0.09120610304869037 0.49442030470258147 0.057558760016644284 0.5495288823237355 0.441530501373377 0.8877041827582998 0.3509150125520787 0.11706701642760586;
 0.14299168205283586 0.7615106317174722 0.6182180633162611 0.10112267612279024 0.08410680611499743 0.70096913145912 0.07276300636419353 0.8218600592903562 0.7062422271564962 0.08134878064189976;
 0.08483771408519192 0.9866395785011755 0.3742707957561203 0.3706421470668909 0.8127995672575026 0.9472485773838587 0.9860010638228709 0.7533781852589416 0.37625958553091576 0.08350071669866876;
 0.7771469159274368 0.558404249735805 0.4242220092469763 0.906354385094736 0.11119748230615134 0.49262510429085915 0.011353644767419069 0.46866064199412627 0.05630327568183735 0.11881791626807192
	)");

  Matrix< type > R = Matrix< type >(R"(
	17.65375032902533 21.07743155269566 13.131758338201784 16.74839022420526 17.927977011615813 20.22938530811436 20.529794896584928 14.58108294282081 18.423144097508008 15.363132689593838;
 14.02558485097405 17.030336537971348 12.2874095538646 13.101763289734427 16.71460037134492 19.125720202406935 18.355544534424975 13.05653073403875 13.53330120544074 10.320520518481292;
 21.813745368012192 20.97009202113295 16.293475410477203 15.977915074967141 17.11663682751735 19.611301534809847 24.152211727513194 18.47824572789207 20.15763777419184 16.167971483151913;
 12.860786983743584 17.601556570943064 14.297513882534167 11.875572395335523 17.409960615139056 16.273151142191693 18.241642437389242 14.880342676810379 16.365762263149556 10.548746423044278;
 10.26443170727428 8.82267821074432 9.975965152428703 11.948799980334396 12.873415143827918 11.759767414343877 12.49654241041717 10.128516971678543 9.914222598645264 8.76174736862473;
 16.95270529689114 17.925397869429766 8.210063843247397 10.316333308478642 13.51810114686768 14.725355410758457 18.97713675746751 14.904039113131432 13.84568068092269 11.527084160681756;
 19.113435283946355 20.575202949791315 20.916632431980066 14.104819753350627 19.398781461955668 19.3785937589834 20.138472099346185 17.080931748439333 20.563034084826075 16.711952914431855;
 16.554809023266376 15.703994676294837 16.735924990725564 18.475582007553072 19.246229767002973 21.888400380932993 20.669975266088215 11.561701230020535 18.805485965023962 15.849270785277026;
 21.644584191520874 19.761921876833732 19.82343723394118 18.423929776728762 17.735125590433455 19.494351972866813 23.438543485106216 16.621518853616642 20.91750746252872 17.899475004662914;
 11.993670215711768 13.028172997055185 10.83336266794142 13.541779371028857 18.4446562699654 18.235495551535028 19.43300996019818 10.24661965309823 13.374198449498195 10.524216858294098
	)");
  
	gemm_tn_novector(alpha, A, B, beta, C);



	ASSERT_TRUE( R.AllClose(C) );
   
}

#include "draw.hpp"
// #include "Conic.hpp"
#include "random"
#include "chrono"


// faire une fonction draw_conic à qui on donne un std::vector<Point> et qui draw la conic pour alléger les fonctions draw
void draw_conic(std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){

    Conic C1(vector); //création de la conique
    // on transmet ses coeff à la conique de geogebra
    Eigen::VectorXd conic1(6);
    conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // on la push
    viewer.push_conic(conic1, r, g, b);
}

void draw_1(Viewer_conic &viewer){
    // on choisi 5 points de contrôle
    //en bleu
    Point p1(5.0,5.0,1.0), p2(-3.0,2.0,1.0), p3(-4.0,-4.0,1.0), p4(1.0,-2.0,1.0), p5(0.0,1.0,1.0);
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    draw_conic(v1,viewer,0,0,200);
}

void draw_random(Viewer_conic &viewer, const unsigned int n){ 
    //conique de (n) points random
    //en ROUGE

    // selection de la seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::cout << "seed : " << seed << std::endl;

    // selection du générateur random 
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> uniformRealDistribution(-5,5); //distribution de réels entre -5 et 5
    std::vector<Point> v2;
    for(unsigned int i=1; i <n+1 ; i++){
        Point p (uniformRealDistribution(generator), uniformRealDistribution(generator), uniformRealDistribution(generator));
        v2.push_back(p); //ajout de chaque point au vecteur v2
    }
    draw_conic(v2,viewer,200,0,0);
}

void draw_types(Viewer_conic &viewer){
    //créée des coniques à partir des coef
    //cercle : a = c et b=0
    Conic C1();
    // différents types de coniques, tester avec plus que 5 points, avec w=0, etc (voir poly ce qu'il dmd)
}



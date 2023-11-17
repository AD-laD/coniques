#include "draw.hpp"
#include "Conic.hpp"
#include "random"
#include "chrono"


// faire une fonction draw_conic à qui on donne un std::vector<Point> et qui draw la conic pour alléger les fonctions draw
void draw_conic(std::vector<Point> vector, unsigned int n, Viewer_conic &viewer){

    Conic C1(vector); //pas ok

    // std::cout <<"test"<<std::endl;    
    // on transmet ses coeff à la conique de geogebra
    Eigen::VectorXd conic1(6);
    conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // conic1 << 4,5,7,2,1,7;
    std::cout << C1.a()<<std::endl;

    // on la push
    viewer.push_conic(conic1, 0, 0, 200);
}

void draw_1(Viewer_conic &viewer){
    // on choisi 5 points de contrôle
    Point p1(5.0,5.0,1.0),p2(-3.0,2.0,1.0),p3(-4.0,-4.0,1.0),p4(1.0,-2.0,1.0),p5(0.0,1.0,1.0);
    //check : ok
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    draw_conic(v1, v1.size(),viewer);
    //check : ok
    // on construit la conique
    // Conic C1(v1); //pas ok

    // // std::cout <<"test"<<std::endl;    
    // // on transmet ses coeff à la conique de geogebra
    // Eigen::VectorXd conic1(6);
    // conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // // conic1 << 4,5,7,2,1,7;
    // std::cout << C1.a()<<std::endl;

    // // on la push
    // viewer.push_conic(conic1, 0, 0, 200);
}

void draw_random(Viewer_conic viewer){ //conique de points random

    // selection de la seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::cout << "seed : " << seed << std::endl;

    // selection du générateur random 

    //important : jsp s'il faut mettre la def des pts random dans le draw ou pas a voir ptet faudra faire une fonction à part
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> uniformRealDistribution(-5,5); //distribution de réels entre -5 et 5
    std::vector<Point> v2;
    for(unsigned int i=1; i <6 ; i++){
        Point p (uniformRealDistribution(generator), uniformRealDistribution(generator), uniformRealDistribution(generator));
        v2.push_back(p); //ajout de chaque point au vecteur v2
    }
    Conic C2(v2);
    Eigen::VectorXd conic2(6);
    conic2 << C2.a(), C2.b(), C2.c(), C2.d(), C2.e(), C2.f();
    viewer.push_conic(conic2, 0, 0, 200);

}

void draw_3(){
    // différents types de coniques, tester avec plus que 5 points, avec w=0, etc (voir poly ce qu'il dmd)
}



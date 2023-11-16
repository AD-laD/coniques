#include "draw.hpp"
#include "Conic.hpp"


// faire une fonction draw_conic à qui on donne un std::vector<Point> et qui draw la conic pour alléger les fonctions draw
void draw_1(Viewer_conic viewer){
    // on choisi 5 points de contrôle
    Point p1(5,5,1),p2(-3,2,1),p3(-4,-4,1),p4(1,-2,1),p5(0,1,1);
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    // on construit la conique
    Conic C1(v1);
    // on transmet ses coeff à la conique de geogebra
    Eigen::VectorXd conic1(6);
    conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // on la push
    viewer.push_conic(conic1, 0,0, 200);
}

void draw_2(){
    // tester de faire une conique avec des points random
}

void draw_3(){
    // différents types de coniques, tester avec plus que 5 points, avec w=0, etc (voir poly ce qu'il dmd)
}



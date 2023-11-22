#include "ConicTypes.hpp"

void set_w_to_conic(Viewer_conic &viewer, const double w){
    //on choisi la coordonnée w des 5 points de contrôles, le reste est fixé
    Point p1(5.0,5.0,w), p2(-3.0,2.0,w), p3(-4.0,-4.0,w), p4(1.0,-2.0,w), p5(0.0,1.0,w);
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    draw::conic_from_points(v1,viewer,0,0,200);//on créée la conique à partir des points du vecteur v1
}

void circle_conic(Viewer_conic &viewer){
    //cercle : a = c et b = 0
    std::vector<double> vCercle = {1.0,0.0,1.0,5.0,3.0,2.0}; //on met des coeff qui respectent la condition
    std::string type="cercle";
    draw::conic_from_coeff(vCercle, type, viewer, 0, 200, 0); //on créée la conique à partir de ses coeffs
}

void ellipse_conic(Viewer_conic &viewer){
    //ellipse : b()*b()-4*a()*c()<0
    std::vector<double> vEllipse = {1.0, 3.0, 5.0, 5.0, 3.0, 2.0}; //on met des coeff qui respectent la condition
    std::string type="ellipse";
    draw::conic_from_coeff(vEllipse, type, viewer, 0, 200, 0); //on créée la conique à partir de ses coeffs
}

void parabole_conic(Viewer_conic &viewer){
    //parabole : b()*b()-4*a()*c()==0
    std::vector<double> vParab = {1.0, 2.0, 1.0, 5.0, 3.0, 2.0}; //on met des coeff qui respectent la condition
    std::string type="parabole";
    draw::conic_from_coeff(vParab, type, viewer, 0, 200, 0); //on créée la conique à partir de ses coeffs
}

void hyperbole_conic(Viewer_conic &viewer){
    //hyperbole : b()*b()-4*a()*c()>0
    std::vector<double> vHyper = {5.0, 3.0, 0.0, 1.0, -1.0, -2.0}; //on met des coeff qui respectent la condition
    std::string type = "hyperbole";
    draw::conic_from_coeff(vHyper, type, viewer, 0, 200, 0); //on créée la conique à partir de ses coeffs

}
#include "Droite.hpp"

Droite::Droite(const double &a, const double &b, const double &c) : m_a(a),m_b(b),m_c(c){} 

Droite::Droite(const Droite &d) : m_a(d.m_a),m_b(d.m_b),m_c(d.m_c){} //copy constructor

double Droite::a(){return m_a;} //getter de A
double Droite::b(){return m_b;} //getter de B
double Droite::c(){return m_c;} //getter de C

void Droite::set_a(double& a){m_a=a;} 
void Droite::set_b(double& b){m_b=b;} 
void Droite::set_c(double& c){m_c=c;} 


Droite Droite::passage(Point& x1, const Point& x2){ 
    //si une droite passe par x1 et x2, elle est égale au prodvect de x1 et x2
    Point result = x1.prod_vect(x2); //produit vectoriel de x1 et x2
    double a = result.x();
    double b = result.y();
    double c = result.w();
    set_a(a);
    set_b(b);
    set_c(c);
}

Point Droite::intersection(const Droite& l2){ //calcule l'intersection entre 2 droites
    //faire le prod_vect pour la droite
    Point c;
    double cx= m_b*l2.m_c - m_c*l2.m_b;
    double cy = m_c*l2.m_a - m_a*l2.m_c;
    double cw = m_a*l2.m_b - m_b*l2.m_a;
    c.set_x(cx);
    c.set_y(cy);
    c.set_w(cw);
    return c;
}
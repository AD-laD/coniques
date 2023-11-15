#include "point.hpp"

Point::Point(const double &x, const double &y, const double &w) : m_x(x),m_y(y),m_w(w){} 

Point::Point(const Point &p) : m_x(p.m_x),m_y(p.m_y),m_w(p.m_w){} //copy constructor

double Point::x(){return m_x;} //getter de x
double Point::y(){return m_y;} //getter de y
double Point::w(){return m_w;} //getter de w

void Point::set_x(double& x){m_x=x;} //setters
void Point::set_y(double& y){m_y=y;}
void Point::set_w(double& w){m_w=w;}

Point Point::prod_vect(const Point& b){
    Point c;
    c.m_x = m_y*b.m_w - m_w*b.m_y;
    c.m_y = m_w*b.m_x - m_x*b.m_w;
    c.m_w = m_x*b.m_y - m_y*b.m_x;
    return c;
}
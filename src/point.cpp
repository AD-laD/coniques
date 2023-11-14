#include "point.hpp"

Point::Point(const double &x, const double &y, const double &w) : m_x(x),m_y(y),m_w(w){} 

Point::Point(const Point &p) : m_x(p.m_x),m_y(p.m_y),m_w(p.m_w){} //copy constructor

Point Point::prod_vect(Point& a, Point& b){
    Point c;
    c.m_x = a.m_y*b.m_w - a.m_w*b.m_y;
    c.m_y = a.m_w*b.m_x - a.m_x*b.m_w;
    c.m_w = a.m_x*b.m_y - a.m_y*b.m_x;
    return c;
}

double Point::x(){return m_x;} //getter de x
double Point::y(){return m_y;} //getter de y
double Point::w(){return m_w;} //getter de w
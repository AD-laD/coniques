#include "Point.hpp"

Point::Point(const double &x, const double &y, const double &w) : m_x(x),m_y(y),m_w(w){} 

Point::Point(const Point &p) : m_x(p.m_x),m_y(p.m_y),m_w(p.m_w){} //copy constructor

double Point::x()const{return m_x;} //getter de x
double Point::y()const{return m_y;} //getter de y
double Point::w()const{return m_w;} //getter de w

void Point::set_x(const double& x){m_x=x;} //setters
void Point::set_y(const double& y){m_y=y;}
void Point::set_w(const double& w){m_w=w;}
#pragma once
#include <iostream>
#include <vector>

#include <C:\eigen-3.4.0\Eigen\Dense>

class Point {

    private :
        double m_x,m_y;
        int m_w;
    
    public :
        Point(const double &x=0, const double &y=0, const double &w=1); // default constructor
        Point(const Point &p); // A FAIRE copy constructor

        ~Point() = default; //destrucor

        Point prod_vect(Point& a, Point& b); // A FAIRE
        double x(); // A FAIRE pour y et w

};

// a mettre dans un point.cpp plus tard

Point::Point( const double &x, const double &y, const double &w) : m_x(x),m_y(y),m_w(w){}

Point::Point(const Point &p){}

double Point::x(){return m_x;}

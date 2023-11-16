#include <iostream>
#include <vector>
#include "Conic.hpp"

#include <C:\eigen-3.4.0\Eigen\Dense>

//setter
//template <typename T>
void Conic::set_value(unsigned int i, double& value){
    m_coeff[i] = value;
}
//template <typename T>
void Conic::set_vector(std::vector<double> vect){
    m_coeff = vect;
}

//template <typename T>
void Conic::set_vector(Eigen::VectorXd vect){
    for(int i=0;i<6;i++) m_coeff[i] = vect[i];
}

//getter

double Conic::a(){return(m_coeff[0]);}
//template <typename T>
double Conic::b(){return(m_coeff[1]);}
//template <typename T>
double Conic::c(){return(m_coeff[2]);}
//template <typename T>
double Conic::d(){return(m_coeff[3]);}
//template <typename T>
double Conic::e(){return(m_coeff[4]);}
//template <typename T>
double Conic::f(){return(m_coeff[5]);}

Conic::Conic(std::vector<Point> point_vector){

    int n = point_vector.size();
    //if(n<5){} error message not enough points
    //in(n>5){this->set_vector(moindres_carres(point_vector))}
    Eigen::MatrixXd A(n,6);
    int i=0;
    for(Point p : point_vector){ 
        A(i,0) = p.x()*p.x();
        A(i,1) = p.x()*p.y();
        A(i,2) = p.y()*p.y();
        A(i,3) = p.x()*p.w();
        A(i,4) = p.y()*p.w();
        A(i,5) = p.w()*p.w();
        i++;
    }
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeFullV);
    Eigen::VectorXd x=svd.matrixV().rightCols(1);
    this->set_vector(x);

}


std::vector<Point> moindres_carres(std::vector<Point> point_vector){

}

// conic type
//template <typename T>
bool Conic::is_cercle(){return(a()==c() && b()==0);}
//template <typename T>
bool Conic::is_ellipse(){return(b()*b()-4*a()*c()<0);}
//template <typename T>
bool Conic::is_parabole(){return(b()*b()-4*a()*c()==0);}
//template <typename T>
bool Conic::is_hyperbole(){return(b()*b()-4*a()*c()>0);}
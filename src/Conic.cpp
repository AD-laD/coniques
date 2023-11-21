#include <iostream>
#include <vector>
#include "Conic.hpp"

#include <C:\eigen-3.4.0\Eigen\Dense>

//setter

void Conic::set_value(unsigned int i, double& value){ //pas verif
    m_coeff[i] = value;
}

void Conic::set_vector(std::vector<double> &vect){
    //pour les erreurs ; verif que vect a bien la meme taille que la conic
    m_coeff = vect;
}

void Conic::set_vector(Eigen::VectorXd &vect){
    for(int i=0;i<6;i++) m_coeff[i] = vect[i];
}


//getter
double Conic::a(){return(m_coeff[0]);}
double Conic::b(){return(m_coeff[1]);}
double Conic::c(){return(m_coeff[2]);}
double Conic::d(){return(m_coeff[3]);}
double Conic::e(){return(m_coeff[4]);}
double Conic::f(){return(m_coeff[5]);}

std::vector<double> Conic::get_coeff(){
    std::vector<double> coeff;
    coeff = m_coeff;
    return(coeff);
}

double Conic::get_coeff_from_i(const unsigned int i){
    return m_coeff[i];
}

Conic::Conic(std::vector<Point> point_vector){

    int n = point_vector.size();
    assert ((n>=5) && "erreur : il faut au moins 5 points de controle pour construire la conique");
    //verifie à l'exécution qu'il y a bien au moins 5 points de controles

    //if(n>5){this->set_vector(moindres_carres(point_vector))}
    Eigen::MatrixXd A(n,6);

    for(int i=0;i<n;i++){
        A(i,0) = point_vector[i].x()*point_vector[i].x();
        A(i,1) = point_vector[i].x()*point_vector[i].y();
        A(i,2) = point_vector[i].y()*point_vector[i].y();
        A(i,3) = point_vector[i].x()*point_vector[i].w();
        A(i,4) = point_vector[i].y()*point_vector[i].w();
        A(i,5) = point_vector[i].w()*point_vector[i].w();
    }
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeFullV);
    Eigen::VectorXd x=svd.matrixV().rightCols(1);
    std::vector<double> coefficients;
    for (int i = 0; i < x.size(); ++i) {
        coefficients.push_back(x(i));
    }
    set_vector(coefficients);
}
Conic::Conic(std::vector<Droite> droite_vector){

    int n = droite_vector.size();
    assert ((n>=5) && "erreur : il faut au moins 5 points de controle pour construire la conique");
    //verifie à l'exécution qu'il y a bien au moins 5 points de controles

    //if(n>5){this->set_vector(moindres_carres(point_vector))}
    Eigen::MatrixXd A(n,6);

    for(int i=0;i<n;i++){
        A(i,0) = droite_vector[i].a()*droite_vector[i].a();
        A(i,1) = droite_vector[i].a()*droite_vector[i].b();
        A(i,2) = droite_vector[i].b()*droite_vector[i].b();
        A(i,3) = droite_vector[i].a()*droite_vector[i].c();
        A(i,4) = droite_vector[i].b()*droite_vector[i].c();
        A(i,5) = droite_vector[i].c()*droite_vector[i].c();
    }
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeFullV);
    Eigen::VectorXd x=svd.matrixV().rightCols(1);
    std::vector<double> coefficients;
    for (int i = 0; i < x.size(); ++i) {
        coefficients.push_back(x(i));
    }
    set_vector(coefficients);
}

Conic::Conic() : m_coeff({0,0,0,0,0,0}){}

Conic::Conic(std::vector<double> vector) : m_coeff(vector){}

Conic Conic::operator/(const double a){ //pas encore verif

    //gestion des erreurs : verif que a n'est pas égal a 0 sinn arreter le programme
    //static_assert ((a=0) && "erreur : on essaie de diviser une conique par 0");
    std::for_each(m_coeff.begin(),m_coeff.end(),[a](double x){x/a;});
    return(*this);
}

Conic Conic::operator*(const double a) { 
    std::vector<double> resultCoeffs;
    const std::vector<double>& coeffs = get_coeff();
    for (size_t i = 0; i < 6; ++i) {
        resultCoeffs.push_back(coeffs[i] * a);
    }
    Conic result;
    result.set_vector(resultCoeffs);
    return result;
}

Conic Conic::operator+(Conic& C){
    std::vector<double> resultCoeffs;
    const std::vector<double>& coeffs1 = get_coeff();
    const std::vector<double>& coeffs2 = C.get_coeff();
    for(int i=0;i<6;i++){
        resultCoeffs.push_back(coeffs1[i] + coeffs2[i]);
    }
    Conic result;
    result.set_vector(resultCoeffs);
    return result;
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

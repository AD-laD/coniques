#include "Conic.hpp"

//default constructor
Conic::Conic() : m_coeff({0,0,0,0,0,0}){} //par défaut, les coeff sont égaux à 0

//setters

void Conic::set_vector(const std::vector<double> &vect){ //permet de set un vector de double de coeff à une conique
    assert ((vect.size()==6) && "erreur : le vecteur de coeff ne contient pas 6 valeurs");
    //pour les erreurs ; verif que vect a bien la meme taille que la conic
    m_coeff = vect;
}


//getters : ils retournent les valeurs des coeffs
double Conic::a()const{return(m_coeff[0]);}
double Conic::b()const{return(m_coeff[1]);}
double Conic::c()const{return(m_coeff[2]);}
double Conic::d()const{return(m_coeff[3]);}
double Conic::e()const{return(m_coeff[4]);}
double Conic::f()const{return(m_coeff[5]);}

//getter : permet de get tout le vecteur de coeff de la conique
std::vector<double> Conic::get_coeff() const{
    std::vector<double> coeff;
    coeff = m_coeff;
    return(coeff);
}

//permet de get un coeff au rang i
double Conic::get_coeff_from_i(const unsigned int i) const{
    return m_coeff[i];
}

Conic::Conic(const std::vector<Point> point_vector){ //connstructeur de conique à partir d'un vector de Points
    int n = point_vector.size();
    assert ((n>=5) && "erreur : il faut au moins 5 points de controle pour construire la conique");
    //verifie à l'exécution qu'il y a bien au moins 5 points de controle

    Eigen::MatrixXd A(n,6); //création de matrice de taille n par 6

    for(int i=0;i<n;i++){ 
        //pour chaque colonne, on fait :
        A(i,0) = point_vector[i].x()*point_vector[i].x();//xi au carré sur la première ligne
        A(i,1) = point_vector[i].x()*point_vector[i].y();//xi*yi sur la deuxième ligne
        A(i,2) = point_vector[i].y()*point_vector[i].y();//yi au carré
        A(i,3) = point_vector[i].x()*point_vector[i].w();//xi*wi
        A(i,4) = point_vector[i].y()*point_vector[i].w();//yi*wi
        A(i,5) = point_vector[i].w()*point_vector[i].w();//wi au carré
    }
    //noyau de A
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU|Eigen::ComputeFullV);
    Eigen::VectorXd x=svd.matrixV().rightCols(1);
    std::vector<double> coefficients;
    for (int i = 0; i < x.size(); ++i) {
        coefficients.push_back(x(i));//on met les valeurs de xi dans le vecteur coefficient
    }
    set_vector(coefficients);//on set ce vecteur de coefficients à la conique
}

Conic::Conic(const std::vector<double> vector) : m_coeff(vector){}//constructeur à partir d'un vecteur de coefficients

//opérateurs

Conic Conic::operator/(const double a) const{ //division d'une conique par un double
    std::for_each(m_coeff.begin(),m_coeff.end(),[a](double x){x=x/a;});
    return(*this);
}

Conic Conic::operator*(const double a) const{ //multiplication d'une conique par un double
    std::vector<double> resultCoeffs;
    const std::vector<double>& coeffs = get_coeff();
    for (size_t i = 0; i < 6; ++i) {
        resultCoeffs.push_back(coeffs[i] * a);
    }
    Conic result;
    result.set_vector(resultCoeffs);
    return result;
}

Conic Conic::operator+(const Conic& C) const{ //addition de 2 coniques
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


// types de conique 
bool Conic::is_cercle(){return(a()==c() && b()==0);}
bool Conic::is_ellipse(){return(b()*b()-4*a()*c()<0);}
bool Conic::is_parabole(){return(b()*b()-4*a()*c()==0);}
bool Conic::is_hyperbole(){return(b()*b()-4*a()*c()>0);}

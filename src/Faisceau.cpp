#include "Faisceau.hpp"


Faisceau::Faisceau(Conic Ca, Conic Cb){
    // on verifie que Ca et Cb normées
    // norm_a = somme des coeff au carré
    std::vector<double> coeff_a = Ca.get_coeff();
    double sum_a = 0;
    std::for_each(coeff_a.begin(), coeff_a.end(), [&sum_a](double x){sum_a+=x*x;});
    
    std::vector<double> coeff_b = Cb.get_coeff();
    double sum_b = 0;
    std::for_each(coeff_b.begin(), coeff_b.end(), [&sum_b](double x){sum_b+=x*x;});

    if(std::sqrt(sum_a)!=1){m_Ca = Ca/std::sqrt(sum_a);}
    if(std::sqrt(sum_b)!=1){m_Cb = Cb/std::sqrt(sum_b);}
    
    // chacune des i coniques du faisceau vaut : cos(t)*Ca+sin(t)*Cb
    // avec t = pi/i, i dans [0,pi]
    Conic C1;
    m_Ci.resize(num_conic);
    for(int i=0;i<num_conic;i++){
        //set_Ci(i,Ca*std::cos(3.141592/num_conic*i) + Ca*std::sin(3.141592/num_conic*i)) ;
        set_Ci(i,C1);
    }
}

void Faisceau::set_num_conic(int a){num_conic = a;}
void Faisceau::set_Ci(int index, const Conic C0){m_Ci[index] = C0;}
int Faisceau::get_num_conic(){return(num_conic);}

std::vector<Conic> Faisceau::get_Ci(){return(m_Ci);}
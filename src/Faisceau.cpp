#include "Faisceau.hpp"

Faisceau::Faisceau(Conic& Ca, Conic& Cb){
    // on verifie que Ca et Cb normées
    // norm_a = somme des coeff au carré
    std::vector<double> coeff_a = Ca.get_coeff();
    double sum_a = 0;
    std::for_each(coeff_a.begin(), coeff_a.end(), [&sum_a](double x){sum_a+=x*x;});
    
    std::vector<double> coeff_b = Cb.get_coeff();
    double sum_b = 0;
    std::for_each(coeff_b.begin(), coeff_b.end(), [&sum_b](double x){sum_b+=x*x;});

    Conic newCa=Ca/std::sqrt(sum_a);
    Conic newCb =Cb/std::sqrt(sum_b);

// a supp
    if(std::sqrt(sum_a)!=1){set_Ca(newCa);}
    if(std::sqrt(sum_b)!=1){set_Cb(newCb);}

    // chacune des i coniques du faisceau vaut : cos(t)*Ca+sin(t)*Cb
    // avec t = pi/i, i dans [0,pi]
    // Conic C1;
    // Conic C2;
    // mettre new ca et new cb a la place de ca et cb
    m_Ci.resize(m_num_conic);
    for(int i=0;i<m_num_conic;i++){
        double t = 3.141592/m_num_conic*i; 
        Conic C1 = Ca * std::cos(t);
        Conic C2 = Cb * std::sin(t);
        Conic Cc = C1 + C2;
        set_Ci(i,Cc);
    }
}

void Faisceau::set_num_conic(const unsigned int &a){m_num_conic = a;}
void Faisceau::set_Ci(int index, Conic &C0){
        std::vector<double> coeff = C0.get_coeff();
        m_Ci[index].set_vector(coeff);
        }
void Faisceau::set_Ca(const Conic &Ca){m_Ca=Ca;}
void Faisceau::set_Cb(const Conic &Cb){m_Cb=Cb;}
int Faisceau::get_num_conic(){return(m_num_conic);}

std::vector<Conic> Faisceau::get_Ci(){return(m_Ci);}
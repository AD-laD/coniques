#include "Faisceau.hpp"

Faisceau::Faisceau(const Conic& Ca, const Conic& Cb){
    // on verifie que Ca et Cb normées
    // norm_a = somme des coeff au carré
    std::vector<double> coeff_a = Ca.get_coeff();
    double sum_a = 0;
    std::for_each(coeff_a.begin(), coeff_a.end(), [&sum_a](double x){sum_a+=x*x;});//on fait la somme des coeff au carré
    
    std::vector<double> coeff_b = Cb.get_coeff();
    double sum_b = 0;
    std::for_each(coeff_b.begin(), coeff_b.end(), [&sum_b](double x){sum_b+=x*x;});//on fait la somme des coeff au carré

    Conic newCa=Ca/std::sqrt(sum_a); //on divise Ca par sa norme
    Conic newCb =Cb/std::sqrt(sum_b); //on divise Cb par sa norme

    m_Ci.resize(m_num_conic);//on resize le vector de coniques 
    for(int i=0;i<m_num_conic;i++){
        double t = 3.141592/m_num_conic*i; //pas 
        // chacune des i coniques du faisceau vaut : cos(t)*Ca+sin(t)*Cb
        // avec t = pi/i, i dans [0,pi]
        Conic C1 = newCa * std::cos(t);
        Conic C2 = newCb * std::sin(t);
        Conic Cc = C1 + C2;
        set_Ci(i,Cc);
    }
}

void Faisceau::set_num_conic(const unsigned int &a){m_num_conic = a;}
void Faisceau::set_Ci(const unsigned int index, const Conic &C0){
        std::vector<double> coeff = C0.get_coeff();
        m_Ci[index].set_vector(coeff);
        }
void Faisceau::set_Ca(const Conic &Ca){m_Ca=Ca;}
void Faisceau::set_Cb(const Conic &Cb){m_Cb=Cb;}
int Faisceau::get_num_conic()const{return(m_num_conic);}

std::vector<Conic> Faisceau::get_Ci()const{return(m_Ci);}
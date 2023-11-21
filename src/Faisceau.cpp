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
    Conic newCb = Cb/std::sqrt(sum_b);

    if(std::sqrt(sum_a)!=1){set_Ca(newCa);}
    if(std::sqrt(sum_b)!=1){set_Cb(newCb);}

    // chacune des i coniques du faisceau vaut : cos(t)*Ca+sin(t)*Cb
    // avec t = pi/i, i dans [0,pi]
    Conic C1;
    m_Ci.resize(m_num_conic);
    for(int i=0;i<m_num_conic;i++){
        //set_Ci(i,Ca*std::cos(3.141592/m_num_conic*i)+ Cb*std::sin(3.141592/m_num_conic*i));
        double t = 3.141592/m_num_conic*i; 
        Conic C1 = Ca * std::cos(t);
        Conic C2 = Cb * std::sin(t);
        Conic Cc = C1 + C2;
        set_Ci(i,Cc);

        
        //std::vector<double> coeff = {1.0+0.1*i,2.0+0.1*i,2.0*i,3.0*i,2.0*i,2.0*i};
        //Cc.set_vector(coeff);
        // std::cout << "le coeff 1 de Cc vaut"<<Cc.a()<<std::endl;
        // std::cout <<"le a de ci de i vaut " <<m_Ci[i].a()<<std::endl;
    }
}

void Faisceau::set_num_conic(const unsigned int &a){m_num_conic = a;}
void Faisceau::set_Ci(int index, Conic &C0){
        std::vector<double> coeff = C0.get_coeff();
        // std::cout<<"le coeff 1 du vect "<<coeff[1]<<std::endl;
        m_Ci[index].set_vector(coeff);
        //std::cout<<"le coeff b de m_ci vaut "<<m_Ci[index].b()<<std::endl;
        }
void Faisceau::set_Ca(const Conic &Ca){m_Ca=Ca;}
void Faisceau::set_Cb(const Conic &Cb){m_Cb=Cb;}
int Faisceau::get_num_conic(){return(m_num_conic);}

std::vector<Conic> Faisceau::get_Ci(){return(m_Ci);}
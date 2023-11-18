#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//#include <numbers>
#include "Conic.hpp"

#include <C:\eigen-3.4.0\Eigen\Dense>

class Faisceau {
    private : 
        Conic m_Ca, m_Cb; // Coniques de base
        std::vector<Conic> m_Ci; // Coniques du faisceau
        int num_conic=10; // le nombre de coniques du faisceau
    public :
        Faisceau(Conic Ca, Conic Cb);
        ~Faisceau() = default;
        void set_num_conic(int a); 
        int get_num_conic();
        std::vector<Conic> get_Ci();
};

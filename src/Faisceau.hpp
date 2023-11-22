#pragma once
#include <algorithm>
#include <cmath>
#include "Conic.hpp"

class Faisceau {
    private : 
        Conic m_Ca, m_Cb; // Coniques de base
        std::vector<Conic> m_Ci; // Coniques du faisceau
        int m_num_conic=20; // le nombre de coniques du faisceau
    public :
        Faisceau(const Conic& Ca, const Conic& Cb); //constructeur du faisceau à partir de Ca et Cb
        ~Faisceau() = default; //constructeur par défaut
        //setters
        void set_num_conic(const unsigned int &a); //permet de set le nombre de coniques du faisceau
        void set_Ci(const unsigned int index, const Conic &C0); 
        void set_Ca(const Conic &Ca); //pour modifier Ca
        void set_Cb(const Conic &Cb); //pour modifier Cb
        //getters
        int get_num_conic() const; //pour obtenir la valeur de num_conic
        std::vector<Conic> get_Ci() const;//pour obtenir le vecteur de conique Ci
};

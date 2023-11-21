#include "Point.hpp"


class Droite {
    private:
    double m_a;
    double m_b;
    double m_c;

    public:
    Droite(const double &a=0, const double &b=0, const double &c=0); // default constructor
    Droite(const Droite &d); // copy constructor

    ~Droite() = default; //destructor

    //getters
    double a();
    double b();
    double c();
        
    //setters
    void set_a(double& a);
    void set_b(double& b);
    void set_c(double& c);

    Droite passage(Point& x1, const Point& x2); //en théorie faut que les 2 soient const, faut modif la fonc prod_vect pour qu'elle soit const
    Point intersection (const Droite& l2);

};

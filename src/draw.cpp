#include "draw.hpp"
// #include "Conic.hpp"
#include "random"
#include "chrono"

//assert : pour des erreurs de code qui pourraient arriver (de notre faute)
//exceptions : pour des erreurs qui pourraient arriver de l'extérieur, à cause d"un souci...


// faire une fonction draw_conic à qui on donne un std::vector<Point> et qui draw la conic pour alléger les fonctions draw
void draw::conic_from_points(std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){

    Conic C1(vector); //création de la conique
    // on transmet ses coeff à la conique de geogebra
    Eigen::VectorXd conic1(6);
    conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // on la push

    try{
        viewer.push_conic(conic1, r, g, b);
    }
    catch (std::runtime_error) {
        // std::cout <<"Erreur lors du dessin de la conique dans le viewer"<<std::endl;
        std::cerr << "erreur lors du dessin de la conique" << std::endl;
    }
}

void draw::classic_conic(Viewer_conic &viewer){
    // on choisi 5 points de contrôle
    //en bleu
    Point p1(5.0,5.0,1.0), p2(-3.0,2.0,1.0), p3(-4.0,-4.0,1.0), p4(1.0,-2.0,1.0), p5(0.0,1.0,1.0);
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    draw::conic_from_points(v1,viewer,0,0,200);
}

void draw::set_w_to_conic(Viewer_conic &viewer, const double w){
    Point p1(5.0,5.0,w), p2(-3.0,2.0,w), p3(-4.0,-4.0,w), p4(1.0,-2.0,w), p5(0.0,1.0,w);
    std::vector<Point> v1{p1,p2,p3,p4,p5};
    draw::conic_from_points(v1,viewer,0,0,200);
}

void draw::random_points(Viewer_conic &viewer, const unsigned int n){ 
    //conique de (n) points random
    //en ROUGE

    // selection de la seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// std::cout << "seed : " << seed << std::endl;

    // selection du générateur random 
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> uniformRealDistribution(-5,5); //distribution de réels entre -5 et 5
    std::vector<Point> v2;
    for(unsigned int i=1; i <n+1 ; i++){
        Point p (uniformRealDistribution(generator), uniformRealDistribution(generator), uniformRealDistribution(generator));
        v2.push_back(p); //ajout de chaque point au vecteur v2
    }
    draw::conic_from_points(v2,viewer,200,0,0);
}

//DRAW TYPES

// void draw_types(Viewer_conic &viewer){
    //créée des coniques à partir des coef
void draw::circle_conic(Viewer_conic &viewer){
    //cercle : a = c et b=0
    Conic cCercle;
    std::vector<double> vCercle = {1.0,0.0,1.0,5.0,3.0,2.0};
    cCercle.set_vector(vCercle);
    Eigen::VectorXd conicCercle(6);
    conicCercle << cCercle.a(), cCercle.b(), cCercle.c(), cCercle.d(), cCercle.e(), cCercle.f();
    // on la push
    assert (cCercle.is_cercle() && "erreur : la conique cercle ne vérifie pas l'équation");

    viewer.push_conic(conicCercle, 0, 200, 0);
}

void draw::ellipse_conic(Viewer_conic &viewer){

    //ellipse
    //b()*b()-4*a()*c()<0
    Conic cEllipse;
    std::vector<double> vEllipse = {1.0, 3.0, 5.0, 5.0, 3.0, 2.0};
    cEllipse.set_vector(vEllipse);
    Eigen::VectorXd conicEllipse(6);
    conicEllipse << cEllipse.a(), cEllipse.b(), cEllipse.c(), cEllipse.d(), cEllipse.e(), cEllipse.f();

    assert (cEllipse.is_ellipse() && "erreur : la conique ellipse ne vérifie pas l'équation");
    viewer.push_conic(conicEllipse, 0, 200, 0);
}

void draw::parabole_conic(Viewer_conic &viewer){

    //parabole
    //b()*b()-4*a()*c()==0
    Conic cParab;
    std::vector<double> vParab = {1.0, 2.0, 1.0, 5.0, 3.0, 2.0};
    cParab.set_vector(vParab);
    Eigen::VectorXd conicParab(6);
    conicParab << cParab.a(), cParab.b(), cParab.c(), cParab.d(), cParab.e(), cParab.f();

    assert (cParab.is_parabole() && "erreur : la conique parabole ne vérifie pas l'équation");
    viewer.push_conic(conicParab, 0, 200, 0);
}

void draw::hyperbole_conic(Viewer_conic &viewer){

    //hyperbole
    //b()*b()-4*a()*c()>0
    Conic cHyper;
    std::vector<double> vHyper = {2.0, 3.0, 1.0, 5.0, 3.0, 2.0};
    cHyper.set_vector(vHyper);
    Eigen::VectorXd conicHyper(6);
    conicHyper << cHyper.a(), cHyper.b(), cHyper.c(), cHyper.d(), cHyper.e(), cHyper.f();

    assert (cHyper.is_hyperbole() && "erreur : la conique hyperbole ne vérifie pas l'équation");

    viewer.push_conic(conicHyper, 0, 200, 0);

}



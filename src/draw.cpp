#include "draw.hpp"
#include "random"
#include "chrono"

void draw::conic_from_points(const std::vector<Point> vector, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){

    Conic C1(vector); //création de la conique à partir d'un vecteur de points
    // on transmet ses coeff à la conique de geogebra
    Eigen::VectorXd conic1(6);
    conic1 << C1.a(), C1.b(), C1.c(), C1.d(), C1.e(), C1.f();
    // on la push
    try{
        viewer.push_conic(conic1, r, g, b);
    }
    catch (std::runtime_error) {
        std::cerr << "erreur lors du dessin de la conique" << std::endl;
    }
}

void draw::conic_from_coeff(const std::vector<double> vector, const std::string type, Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){
    Conic conicFromCoeff;
    conicFromCoeff.set_vector(vector);
    Eigen::VectorXd eigenConic(6);
    eigenConic << conicFromCoeff.a(), conicFromCoeff.b(), conicFromCoeff.c(), conicFromCoeff.d(), conicFromCoeff.e(), conicFromCoeff.f();

    // verification du type
    if(type =="cercle"){
        assert (conicFromCoeff.is_cercle() && "erreur : la conique cercle ne vérifie pas l'équation");
    } else if (type=="ellipse"){
        assert (conicFromCoeff.is_ellipse() && "erreur : la conique ellipse ne vérifie pas l'équation");
    } else if (type=="hyperbole"){
        assert (conicFromCoeff.is_hyperbole() && "erreur : la conique hyperbole ne vérifie pas l'équation");
    } else if (type=="parabole"){
        assert (conicFromCoeff.is_parabole() && "erreur : la conique parabole ne vérifie pas l'équation");
    }
    //on push la conique
    try{
        viewer.push_conic(eigenConic, r, g, b);
    }
    catch (std::runtime_error) {
        std::cerr << "erreur lors du dessin de la conique" << std::endl;
    }
}

std::vector<Point> create_random_points(const unsigned int n){ 
    // selection de la seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // selection du générateur random 
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> uniformRealDistribution(-5,5); //distribution de réels entre -5 et 5
    std::vector<Point> randomPoints; //création du vecteur de points vide
    for(unsigned int i=1; i <n+1 ; i++){
        Point p (uniformRealDistribution(generator), uniformRealDistribution(generator), 1); //x et y sont randoms
        randomPoints.push_back(p); //ajout de chaque point au vecteur v2
    }
    return randomPoints;
}

void draw::faisceau(Viewer_conic &viewer, const unsigned int r, const unsigned int g, const unsigned int b){
    // faisceau basique
    // on contruit nos 2 coniques de base
    std::vector<double> va{1.0, 3.0, 5.0, 5.0, 3.0, 2.0};
    std::vector<double> vb{1.0, -3.0, 3.0, 5.0, -2.0, 1.0};
    Conic Ca(va);
    Conic Cb(vb);
    std::string type = "";
    Faisceau F(Ca, Cb); //on construit le Faisceau à partir des 2 coniques

    // on boucle sur ses coniques
    for(int i=0;i<F.get_num_conic();i++){
        // on transmet ses coeff à la conique de geogebra
        Eigen::VectorXd conic1(6);
        conic1 << F.get_Ci()[i].a(), F.get_Ci()[i].b(), F.get_Ci()[i].c(), F.get_Ci()[i].d(), F.get_Ci()[i].e(), F.get_Ci()[i].f();
        // on la push
        try{
            viewer.push_conic(conic1, r, g, b);
        }
        catch (std::runtime_error) {
            // std::cout <<"Erreur lors du dessin de la conique dans le viewer"<<std::endl;
            std::cerr << "erreur lors du dessin de la conique" << std::endl;
        }
    }
    draw::conic_from_coeff(va, type, viewer, 0,200,0); //on draw Ca et Cb en vert pour les rendre bien visibles
    draw::conic_from_coeff(vb, type, viewer, 0,200,0);
}
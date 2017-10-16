#include "TrainElec.h"
#include <iostream>

TrainElec::TrainElec() : Moyens(100,400,6){}

void TrainElec::affiche(void)const{
	std::cout << "Object : TrainElec\n\tcapacite :" << capacite << "\n\tvitesse : " << vitesse << "\n\tempreinte Carbone : " << empreinteCarbone << std::endl;
}
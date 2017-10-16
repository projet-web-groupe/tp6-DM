#include "Train.h"
#include <iostream>

Train::Train() : Moyens(1000,250,1.5,"Train"){}

void Train::affiche(void)const{
	std::cout << "Object : Train\n\tcapacite :" << capacite << "\n\tvitesse : " << vitesse << "\n\tempreinte Carbone : " << empreinteCarbone << std::endl;
}
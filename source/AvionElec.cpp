#include "AvionElec.h"
#include <iostream>

AvionElec::AvionElec() : Moyens(100,400,6){}

void AvionElec::affiche(void)const{
	std::cout << "Object : AvionElec\n\tcapacite :" << capacite << "\n\tvitesse : " << vitesse << "\n\tempreinte Carbone : " << empreinteCarbone << std::endl;
}
#include "Avion.h"
#include <iostream>

Avion::Avion() : Moyens(150,700,18,"Avion"){}

void Avion::affiche(void)const{
	std::cout << "Object : Avion\n\tcapacite :" << capacite << "\n\tvitesse : " << vitesse << "\n\tempreinte Carbone : " << empreinteCarbone << std::endl;
}

std::string Avion::getType()const{
	return "Avion";
}
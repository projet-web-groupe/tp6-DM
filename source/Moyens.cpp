#include "Moyens.h"
#include <iostream>

Moyens::Moyens(
	const unsigned int _capacite ,
	const unsigned int _vitesse,
	const double _empreinteCarbone,
	const std::string _nom
	)
: capacite(_capacite), vitesse(_vitesse), empreinteCarbone(_empreinteCarbone), nom(_nom){}

const unsigned int Moyens::getCapacite(void)const{
	return capacite;
}
const unsigned int Moyens::getVitesse(void)const{
	return vitesse;
}
const double Moyens::getEmpreinteCarbone(void)const{
	return empreinteCarbone;
}

const std::string& Moyens::getNom(void)const{
	return nom;
}
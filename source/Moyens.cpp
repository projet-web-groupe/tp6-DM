#include Moyens.h
#include <iostream.h>

Moyens(
	const unsigned int _capacite,
	const unsigned int _vitesse,
	const _empreinteCarbone,
	const std::string _nom
	)
: capacite(_capacite), vitesse(_vitesse), empreinteCarbone(_empreinteCarbone), nom(_nom){}

const unsigned int getCapacite(void)const{
	return capacite;
}
const unsigned int getVitesse(void)const{
	return vitesse;
}
const double getEmpreinteCarbone(void)const{
	return empreinteCarbone;
}

const std::string& getNom(void)const{
	return nom;
}

void Moyens::affiche(void)const{}
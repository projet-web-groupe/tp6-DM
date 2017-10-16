#include Moyens.h
#include <iostream.h>

Moyens(
	const unsigned int _capacite = 0,
	const unsigned int _vitesse = 0,
	const _empreinteCarbone = 0
	)
: capacite(_capacite),vitesse(_vitesse),empreinteCarbone(_empreinteCarbone){}

const unsigned int getCapacite(void)const{
	return capacite;
}
const unsigned int getVitesse(void)const{
	return vitesse;
}
const double getEmpreinteCarbone(void)const{
	return empreinteCarbone;
}
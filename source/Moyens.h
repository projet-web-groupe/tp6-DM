#ifndef MOYENS_H
#define MOYENS_H

class Moyens {
protected:
	const unsigned int capacite;
	const unsigned int vitesse;
	const double empreinteCarbone;
	Moyens(
		const unsigned int _capacite = 0,
		const unsigned int _vitesse = 0,
		const _empreinteCarbone = 0
		);
public:
	//pas d'enumeration -> simplification de la lecture du code
	static const int train;  
	static const int avion;  
	static const int avionElec;
	void affiche(void)const = 0;
}

#endif
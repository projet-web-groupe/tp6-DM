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
	void affiche(void)const = 0;
	const unsigned int getCapacite(void)const;
	const unsigned int getVitesse(void)const;
	const double getEmpreinteCarbone(void)const;
}

#endif
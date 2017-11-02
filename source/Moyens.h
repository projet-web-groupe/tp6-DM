#ifndef MOYENS_H
#define MOYENS_H

#include <string>

class Moyens {
protected:
	const unsigned int capacite;
	const unsigned int vitesse;
	const double empreinteCarbone;
	const std::string nom;
	Moyens(
		const unsigned int _capacite = 0,
		const unsigned int _vitesse = 0,
		const double _empreinteCarbone = 0,
		const std::string _nom = "none"
		);
public:
	virtual void affiche(void)const;
	const unsigned int& getCapacite(void)const;
	const unsigned int& getVitesse(void)const;
	const double& getEmpreinteCarbone(void)const;
	const std::string& getNom(void)const;
};

#endif
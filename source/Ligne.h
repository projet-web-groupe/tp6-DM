#ifndef LIGNE_H
#define LIGNE_H

#include "Terminal.h"

template<class T>
class Ligne {
	T typeTransports;
	Terminal origin;
	Terminal destination;
	int nbPassagerJour;
public:
	void affiche(void)const;

};

template<T>
void Ligne::affiche(void)const{
	std::cout << "Object : Ligne\n\tType de transport :" << typeTransports.getNom() << "\n\torigin : " << "recup origin" << "\n\tdestination : " << "recup dest" << "\n\tNombre de passager/jour : " << nbPassagerJour << std::endl;
}

#endif
#ifndef LIGNE_H
#define LIGNE_H

#include "Terminal.h"

template<class T>
class Ligne {
	T typeTransports;
	//Pointeur car relation d'aggregation (destruction d'une ligne != destruction terminal)
	Terminal *origin;
	Terminal *destination;
	//chaque ligne à une frequence (qui peut différer pour un même moyen de transports)
	const int frequence;
public:
	void affiche(void)const;
	const int getFrequence(void)const;
	Ligne(const Terminal* origin,Terminal *destination, const int frequence = 1);

};

template <class T>
Ligne<T>(
	const Terminal* _origin,
	Terminal *_destination, 
	const int _frequence = 1
	) : origin(_origin), destination(_destination),frequence(_frequence)
{

}

template <class T>
void Ligne<T>::affiche(void)const{
	std::cout << "Object : Ligne\n\tType de transport :" << typeTransports.getNom() << "\n\torigin : " << "recup origin" << "\n\tdestination : " << "recup dest" << "\n\tNombre de passager/jour : " << nbPassagerJour << std::endl;
}

template<class T>
const int Ligne<T>::getFrequence(void)const{return frequence;}



#endif
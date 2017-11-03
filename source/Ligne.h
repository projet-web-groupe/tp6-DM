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
	const double frequence; //nb transport par seconde
public:
	void affiche(void)const;
	const int getFrequence(void)const;
	Ligne(const Terminal* origin,Terminal *destination, const int frequence = 1/(24*3600));
	const T& getMoyen()const;
	bool compare(const Ligne& l1, const Ligne& l2)const;
	Terminal * getOrigin()const;
	Terminal * getDestination()const;

};

template <class T>
Ligne<T>::Ligne(
	const Terminal* _origin,
	Terminal *_destination, 
	const int _frequence
	) : origin(_origin), destination(_destination),frequence(_frequence)
{

}

template <class T>
void Ligne<T>::affiche(void)const{
	std::cout << "Object : Ligne\n\tType de transport :" << typeTransports.getNom() << "\n\torigin : " << "recup origin" << "\n\tdestination : " << "recup dest" << "\n\tNombre de passager/jour : " << nbPassagerJour << std::endl;
}

template<class T>
const int Ligne<T>::getFrequence(void)const{return frequence;}

template <class T>
const T& getMoyen()const {
	return typeTransports;
}


//l1 avant l2 ?
template <class T>
bool Ligne<T>::compare(const Ligne& l1, const Ligne& l2)const{
	return l1->destination == l2->origin;
}

template <class T>
Terminal * getOrigin()const{
	return origin;
}
template <class T>
Terminal * getDestination()const{
	return destination;
}

#endif
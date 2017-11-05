#ifndef LIGNE_H
#define LIGNE_H
#include "Terminal.h"
class Terminal;
class Moyens;

template <class T>
class Ligne
{
	
	T &ref;
	//Pointeur car relation d'aggregation (destruction d'une ligne != destruction terminal)
	Terminal *origin;
	Terminal *destination;
	//chaque ligne à une frequence (qui peut différer pour un même moyen de transports)
	const double frequence; //nb transport par seconde
public:
	void affiche(void)const;
	const int getFrequence(void)const;

	Ligne(const T &r,const Terminal* origin,Terminal *destination, const int frequence = 1/(24*3600));
	const T& getMoyen()const;
	Terminal * getOrigin()const;
	Terminal * getDestination()const;
	std::string getType()const;
};


template <class T>
Ligne<T>::Ligne(
	const T &r,
	const Terminal* _origin,
	Terminal *_destination, 
	const int nbPassagerJour
	) :ref(r),origin(_origin), destination(_destination),frequence((nbPassagerJour*24*3600)/ref.getCapacite())
{}

template <class T>
void Ligne<T>::affiche(void)const{
	std::cout << "Object : Ligne\n\tType de transport :" << ref.getNom() << "\n\torigin : " << origin->getNom() << "\n\tdestination : " << destination->getNom() << "\n\tNombre de passager/jour : " << frequence * ref.getCapacite() * 24*3600 << std::endl;
}

template<class T>
const int Ligne<T>::getFrequence(void)const{return frequence;}

template <class T>
const T& Ligne<T>::getMoyen()const {
	return ref;
}


//l1 avant l2 ?
template <class T>
bool operator<(const Ligne<T>& l1, const Ligne<T>& l2);
template <class T>
bool operator<(const Ligne<T>& l1, const Ligne<T>& l2){
	return l1->destination == l2->origin;
}

template <class T>
Terminal * Ligne<T>::getOrigin()const{
	return origin;
}
template <class T>
Terminal * Ligne<T>::getDestination()const{
	return destination;
}



#endif
#include "Ligne.h"

template< class T> 
void Ligne<T>::affiche(void)const{
	std::cout << "Object : Ligne de type:"<< typeTransports << "\n\torigin : " << origin.getNom() << "\n\tdestination : " << destination.getNom() << "\n\t/Fréquence de desserte : " << frequence << std::endl;
}

template< class T> 
const int Ligne<T>::getFrequence(void)const{return frequence;}

template< class T> 
Ligne<T>::Ligne(const T& _typeTransports,const T* _origin,T *_destination, const int _frequence)
	:typeTransports(_typeTransports), origin(_origin),destination(_destination),frequence(_frequence)
	{}

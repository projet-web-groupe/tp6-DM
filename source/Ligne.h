#ifndef LIGNE_H
#define LIGNE_H
#include <iostream>
//#include "Terminal.h"

class Terminal;

template <class T>
class Ligne
{
	//const T typeTransports;
	//Pointeur car relation d'aggregation (destruction d'une ligne != destruction terminal)
	T *origin;
	T *destination;
	//chaque ligne à une frequence (qui peut différer pour un même moyen de transports)
	const int frequence;
public:
	void affiche(void)const;
	const int getFrequence(void)const;
	Ligne(/*const T& _typeTransports,*/const T* _origin,T *_destination, const int _frequence = 1);


};

#endif
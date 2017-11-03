#ifndef VOYAGE_H
#define VOYAGE_H
#include "Ligne.h"
class Moyens;

class Voyage {
	Moyens origin;
	Moyens destination;
	//pointeur car destruction d'un voyage != destruction 
	std::list<Ligne<Moyens>> correspondance;
public:
	Voyage();
	~Voyage();
}

#endif
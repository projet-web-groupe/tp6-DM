#ifndef VOYAGE_H
#define VOYAGE_H
#include "Ligne.h"
class Moyens;

class Voyage {
	
	const Moyens& origin;
	const Moyens& destination;
	//pointeur car destruction d'un voyage != destruction 
	std::list<Ligne<Avion *>> lAvion;
	std::list<Ligne<AvionElec *>> lAvionElectrique;
	std::list<Ligne<Train *>> lTrain;
public:
	Voyage();
	~Voyage();
}

#endif
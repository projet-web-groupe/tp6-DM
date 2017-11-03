#ifndef VOYAGE_H
#define VOYAGE_H
#include "Ligne.h"
class Moyens;

class Voyage {
	
	const Terminal& origin;
	const Terminal& destination;
	//pointeur car destruction d'un voyage != destruction 
	std::list<const Ligne<Moyens>&> correspondance;
public:
	Voyage();
	~Voyage();
	void addCorrespondance(const Ligne<Moyens>& correspondance);
	unsigned double getTime(unsigned long int flux) const;
	unsigned double getEmpreinteCarbone(unsigned long int flux) const;
}

#endif
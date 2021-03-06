#ifndef VOYAGE_H
#define VOYAGE_H
#include <list>
#include "Terminal.h"
#include "Ligne.h"
class Terminal;

class Voyage {
	
	const Terminal& origin;
	const Terminal& destination;
	//pointeur car destruction d'un voyage != destruction 
	std::list<Ligne<Moyens>*> correspondance;
public:
	Voyage(const Terminal& _origin, const Terminal& _destination);
	~Voyage();
	void addCorrespondance(Ligne<Moyens>* correspondance);
	double getTime(unsigned long int flux) const;
	double getEmpreinteCarbone(unsigned long int flux)const;
	void affiche()const;
};

#endif
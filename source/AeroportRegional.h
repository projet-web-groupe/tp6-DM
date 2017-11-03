#ifndef AEROPORTREGIONAL_H
#define AEROPORTREGIONAL_H
#include <iostream>
#include "Terminal.h"
#include "Avion.h"
#include "Ligne.h"

class AeroportRegional: public Terminal{

	protected:
		std::list<Ligne<Avion>*> liaison;
	public:
		AeroportRegional();
		AeroportRegional(double lat, double lon);
		const std::list<Ligne<Avion>*> getLiaison() const;
		void ajoutLigne(Ligne<Avion>* l);
		void suppLigne(Ligne<Avion>* l);
};

#endif
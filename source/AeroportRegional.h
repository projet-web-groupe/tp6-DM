#ifndef AEROPORTREGIONAL_H
#define AEROPORTREGIONAL_H
#include <iostream>
#include "Terminal.h"
#include "Avion.h"
#include "Ligne.h"

class AeroportRegional: public Terminal{

	protected:
		std::list<Ligne<Moyens>*> liaison;
	public:
		AeroportRegional();
		AeroportRegional(double lat, double lon, double t, std::string n);
		void ajoutLigne(Ligne<Moyens>* l, int f);
};

#endif
#ifndef AEROPORTREGIONAL_H
#define AEROPORTREGIONAL_H
#include <iostream>
#include "Terminal.h"
#include "Avion.h"

class AeroportRegional: public Terminal{

	protected:
		Ligne<Avion>* liaison;
	public:
		AeroportRegional();
		AeroportRegional(double lat, double lon, Terminal t);
		const std::list<Ligne<Avion>*> getLiaison() const;
};

#endif
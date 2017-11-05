#ifndef AEROPORTINTERNATIONAL_H
#define AEROPORTINTERNATIONAL_H
#include "Terminal.h"
#include "Avion.h"
#include "Ligne.h"

class AeroportInternational: public Terminal
{
	public:
		AeroportInternational();
		AeroportInternational(double lat, double lon, double t, std::string n);
		~AeroportInternational();
		const std::list<Ligne<Moyens>*> getLiaison() const;
		void ajoutLigne(Ligne<Moyens>* l, int f);

};


#endif
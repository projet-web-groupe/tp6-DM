#ifndef AEROPORTINTERNATIONAL_H
#define AEROPORTINTERNATIONAL_H
#include "Terminal.h"
#include "Avion.h"
#include "Ligne.h"

class AeroportInternational: public Terminal
{
	protected:
		std::list<Ligne<Moyens>*> liaison;
	public:
		AeroportInternational();
		AeroportInternational(double lat, double lon, double t, std::string n);
		const std::list<Ligne<Moyens>*> getLiaison() const;
		void ajoutLigne(Ligne<Moyens>* l, int f);

};


#endif
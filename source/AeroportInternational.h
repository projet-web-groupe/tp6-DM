#ifndef AEROPORTINTERNATIONAL_H
#define AEROPORTINTERNATIONAL_H
#include "Terminal.h"
#include "Avion.h"

class AeroportInternational: public Terminal
{
	protected:
		std::list<Ligne<Avion>*> liaison;
	public:
		AeroportInternational();
		AeroportInternational(double lat, double lon);
		const std::list<Ligne<Avion>*> getLiaison() const;
		void ajoutLigne(Ligne<Avion>* l);
		void suppLigne(Ligne<Avion>* l);

};


#endif
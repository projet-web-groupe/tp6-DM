#ifndef HUBAEROPORT_H
#define HUBAEROPORT_H
#include "Avion.h"
#include "Terminal.h"

class HubAeroport: public Terminal{

	protected:
		std::list<Ligne<Avion>*> liaison;
	public:
		HubAeroport();
		HubAeroport(double lat, double lon);
		const std::list<Ligne<Avion>*> getLiaison() const;
		void ajoutLigne(Ligne<Avion>* l);
		void suppLigne(Ligne<Avion>* l);

};

#endif
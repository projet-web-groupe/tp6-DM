#ifndef HUBAEROPORT_H
#define HUBAEROPORT_H
#include "Avion.h"
#include "Terminal.h"
#include "Ligne.h"

class HubAeroport: public Terminal{

	
	public:
		HubAeroport();
		HubAeroport(double lat, double lon, double t, std::string n);
		~HubAeroport();
		const std::list<Ligne<Moyens>*> getLiaison() const;
		virtual void ajoutLigne(Ligne<Moyens>* l, int f = 0);
		void suppLigne(Ligne<Moyens>* l);

};

#endif
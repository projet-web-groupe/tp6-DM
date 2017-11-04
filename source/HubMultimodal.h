#ifndef HUBMULTIMODAL_H
#define HUBMULTIMODAL_H
#include "HubAeroport.h"
#include "Gare.h"

class HubMultimodal: public HubAeroport{
	Gare gare;
	public:
		HubMultimodal();
		HubMultimodal(double lat, double lon, double t, std::string n);
		void ajouterUneliaisonGare(Ligne<Moyens>* l, int f);
};

#endif
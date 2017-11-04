#include "HubMultimodal.h"

HubMultimodal::HubMultimodal():HubAeroport(){}
HubMultimodal::HubMultimodal(double lat, double lon, double t, std::string n):HubAeroport(lat, lon,t, n){}
HubMultimodal::~HubMultimodal(){}
void HubMultimodal::ajouterUneliaisonGare(Ligne<Moyens>* l, int f)
{
	gare.ajoutLigne(l, f);
}
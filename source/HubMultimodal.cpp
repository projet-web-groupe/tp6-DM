#include "HubMultimodal.h"

HubMultimodal::HubMultimodal():HubAeroport(){}
HubMultimodal::HubMultimodal(double lat, double lon):HubAeroport(lat, lon){}
void HubMultimodal::ajouterUneliaisonGare(Ligne<Train>* l)
{
	gare.ajoutLigne(l);
}
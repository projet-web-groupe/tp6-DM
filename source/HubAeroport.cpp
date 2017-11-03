#include "HubAeroport.h"

HubAeroport::HubAeroport():Terminal(){}

HubAeroport::HubAeroport(double lat, double lon):Terminal(lat,lon)
{}

const std::list<Ligne<Avion>*> HubAeroport::getLiaison() const
{
	return liaison;
}

void HubAeroport::ajoutLigne(Ligne<Avion>* l)
{
	if(liaison.size()<=12)
	{
		liaison.push_back(l);
	}
	else
	{
		std::cout<<"impossible deja relie a un autre aeroport"<<std::endl;
	}
}

void HubAeroport::suppLigne(Ligne<Avion>* l)
{
	liaison.remove(l);
}
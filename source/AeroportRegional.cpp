#include "AeroportRegional.h"

AeroportRegional::AeroportRegional():Terminal(){}

AeroportRegional::AeroportRegional(double lat, double lon):Terminal(lat,lon)
{}

const std::list<Ligne<Avion>*> AeroportRegional::getLiaison() const
{
	return liaison;
}

void AeroportRegional::ajoutLigne(Ligne<Avion>* l)
{
	if(liaison.size()==0)
	{
		liaison.push_back(l);
	}
	else
	{
		std::cout<<"impossible deja relie a un autre aeroport"<<std::endl;
	}
}

void AeroportRegional::suppLigne(Ligne<Avion>* l)
{
	liaison.remove(l);
}


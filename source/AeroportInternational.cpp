#include "AeroportInternational.h"

AeroportInternational::AeroportInternational():Terminal(){}

AeroportInternational::AeroportInternational(double lat, double lon):Terminal(lat,lon)
{}

const std::list<Ligne<Avion>*> AeroportInternational::getLiaison() const
{
	return liaison;
}

void AeroportInternational::ajoutLigne(Ligne<Avion>* l)
{
	if(liaison.size()<=4)
	{
		liaison.push_back(l);
	}
	else
	{
		std::cout<<"impossible deja relie a un autre aeroport"<<std::endl;
	}
}

void AeroportInternational::suppLigne(Ligne<Avion>* l)
{
	liaison.remove(l);
}
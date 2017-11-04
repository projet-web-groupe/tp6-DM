#include "AeroportInternational.h"

AeroportInternational::AeroportInternational():Terminal(){}

AeroportInternational::AeroportInternational(double lat, double lon, double t, std::string n):Terminal(lat,lon,t,n)
{}

const std::list<Ligne<Moyens>*> AeroportInternational::getLiaison() const
{
	return liaison;
}

void AeroportInternational::ajoutLigne(Ligne<Moyens>* l)
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

void AeroportInternational::suppLigne(Ligne<Moyens>* l)
{
	liaison.remove(l);
}
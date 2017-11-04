#include "AeroportRegional.h"

AeroportRegional::AeroportRegional():Terminal(){}

AeroportRegional::AeroportRegional(double lat, double lon, double t, std::string n):Terminal(lat,lon,t,n)
{}

const std::list<Ligne<Moyens>*> AeroportRegional::getLiaison() const
{
	return liaison;
}

void AeroportRegional::ajoutLigne(Ligne<Moyens>* l)
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

void AeroportRegional::suppLigne(Ligne<Moyens>* l)
{
	liaison.remove(l);
}



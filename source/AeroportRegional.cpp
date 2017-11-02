#include "AeroportRegional.h"

AeroportRegional::AeroportRegional():Terminal()
{
	liaison= Ligne<Train>();
}

AeroportRegional::AeroportRegional(double lat, double lon, Terminal t):Terminal(lat,lon)
{
	liaison= Ligne<Train>();
}

const std::list<Ligne<Train>*> Gare::getLiaison() const
{
	return liaison;
}
#include "Gare.h"

  	Gare::Gare():Terminal()
  	{
  		liaison= std::list<Ligne<Train>*>();
  	}
  	Gare::Gare(double lat, double lon):Terminal(lat,lon)
  	{
  		liaison= std::list<Ligne<Train>*>();
  	}
  	const std::list<Ligne<Train>*> Gare::getLiaison() const
  	{
  		return liaison;
  	}
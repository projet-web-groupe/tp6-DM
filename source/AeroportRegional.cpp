#include "AeroportRegional.h"

AeroportRegional::AeroportRegional():Terminal(){}

AeroportRegional::AeroportRegional(double lat, double lon, double t, std::string n):Terminal(lat,lon,t,n)
{}

AeroportRegional::~AeroportRegional(){}

void AeroportRegional::ajoutLigne(Ligne<Moyens>* l, int f)
{
	if(liaison.size()==0)
	{
		 if(l->getMoyen().getType().compare("Avion")==0)
	      {
	        liaison.push_back(l);
	        if((l->getDestination())->getNom().compare(nom)==0)
	          flux.push_back(f);
	        else
	          flux.push_back(0);
	      }
	      else
	        std::cout<<"erreur, c'est une ligne d'avion"<<std::endl;
	}
	else
	{
		std::cout<<"impossible deja relie a un autre aeroport"<<std::endl;
	}
}




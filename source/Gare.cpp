#include "Gare.h"

  	Gare::Gare():Terminal()
  	{}
  	Gare::Gare(double lat, double lon, double t, std::string n):Terminal(lat,lon,t,n)
  	{}

    void Gare::ajoutLigne(Ligne<Moyens>* l, int f)
    {
      if(l->getMoyen().getType().compare("Train")==0)
      {
        liaison.push_back(l);
        if((l->getDestination())->getNom().compare(nom)==0)
          flux.push_back(f);
        else
          flux.push_back(0);
      }
      else
        std::cout<<"erreur, c'est une ligne de train"<<std::endl;
    }

    void Gare::suppLigne(Ligne<Moyens>* l)
    {
      liaison.remove(l);
    }
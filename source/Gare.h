#ifndef GARE_H
#define GARE_H
#include "Terminal.h"
#include "Train.h"
#include "Ligne.h"

class Gare: public Terminal
{
 
  public:
  	Gare();
  	Gare(double lat, double lon, double t, std::string n);
  	void ajoutLigne(Ligne<Moyens>* l, int f = 0);
};


#endif
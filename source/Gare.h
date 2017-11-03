#ifndef GARE_H
#define GARE_H
#include "Terminal.h"
#include "Train.h"

class Gare: public Terminal
{
  protected:
  	std::list<Ligne<Train>*> liaison;
  	

  public:
  	Gare();
  	Gare(double lat, double lon);
  	const std::list<Ligne<Train>*> getLiaison() const;
};


#endif
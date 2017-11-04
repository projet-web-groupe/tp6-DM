#include "Terminal.h"
Terminal::Terminal():latitude(0),longitude(0),liaison(std::list<Ligne<Moyens>*>()),tempsMoyenCorrespondance(0),flux(std::list<int>()),nom("en construction")
{

}

Terminal::Terminal(double lat, double lon, double t, std::string n):tempsMoyenCorrespondance(t)
{
  latitude=lat;
  longitude= lon;
  liaison= std::list<Ligne<Moyens>*>();
  flux= std::list<int>();
  nom=n;
}

Terminal:: ~Terminal()
{

}

const double Terminal::getLat() const
{
  return latitude;
}
const double Terminal::getLon() const
{
  return longitude;
}
const double Terminal::getTMC() const
{
  return tempsMoyenCorrespondance;
}
const std::list<int> Terminal::getFlux() const
{
  return flux;
}
const std::list<Ligne<Moyens>*> Terminal::getLiaison() const
{
  return liaison;
}
void Terminal::setLat(double lat)
{
  latitude=lat;
}
void Terminal::setLon(double lon)
{
  longitude=lon;
}
void Terminal::setTMC(double l)
{
  tempsMoyenCorrespondance=l;
}
void Terminal::setFlux(std::list<int> f)
{
  flux= f;
}
double Terminal::distance(double lat, double lon)
{
  return 60*acos(sin(latitude)*sin(lat)+cos(latitude)*cos(lat)*cos(lon-longitude));
}
const std::string Terminal::getNom()
{
  return nom;
}
void Terminal::setNom(std::string n)
{
  nom=n;
}

void Terminal::ajoutLigne(Ligne<Moyens>* l, int f){}


void Terminal::suppLigne(Ligne<Moyens>* l)
{
  liaison.remove(l);
}
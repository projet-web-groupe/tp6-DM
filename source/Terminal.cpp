#include "Terminal.h"
Terminal::Terminal():latitude(0),longitude(0),liaison(std::list<Ligne<Terminal>*>()),tempsMoyenCorrespondance(std::list<double>()),flux(std::list<int>()),nom("en construction")
{

}

Terminal::Terminal(double lat, double lon)
{
  latitude=lat;
  longitude= lon;
  liaison= std::list<Ligne<Terminal>*>();
  tempsMoyenCorrespondance= std::list<double>();
  flux= std::list<int>();

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
const std::list<double> Terminal::getTMC() const
{
  return tempsMoyenCorrespondance;
}
const std::list<int> Terminal::getFlux() const
{
  return flux;
}
const std::list<Ligne<Terminal>*> Terminal::getLiaison() const
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
void Terminal::setTMC(std::list<double> l)
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


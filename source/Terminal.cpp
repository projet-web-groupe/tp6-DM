#include "Terminal.h"

Terminal::Terminal()
{
  latitude=0;
  longitude=0;
  liaison= std::list<Terminal*>();
  tempsMoyenCorrespondance= std::list<double>();
  flux= std::list<int>();

}

Terminal::Terminal(double lat, double lon)
{
  latitude=lat;
  longitude= lon;
  liaison= std::list<Terminal*>();
  tempsMoyenCorrespondance= std::list<double>();
  flux= std::list<int>();

}

Terminal:: ~Terminal()
{

}

double Terminal::getLat()
{
  return latitude;
}
double Terminal::getLon()
{
  return longitude;
}
std::list<double> Terminal::getTMC()
{
  return tempsMoyenCorrespondance;
}
std::list<double> Terminal::getFlux()
{
  return flux;
}
std::list<Terminal*> Terminal::getLiaison()
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
  return 60*accos(sin(latitude)*sin(lat)+cos(latitude)*cos(lat)*cos(lon-longitude));
}

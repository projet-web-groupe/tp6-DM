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

double Terminal::getLat() const
{
  return latitude;
}
double Terminal::getLon() const
{
  return longitude;
}
double Terminal::getTMC() const
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
<<<<<<< HEAD
const std::string Terminal::getNom()const
=======
std::string Terminal::getNom() const
>>>>>>> 75729ab300005806412176aa6d59f2b42fc7f585
{
  return nom;
}
void Terminal::setNom(std::string n)
{
  nom=n;
}

void Terminal::affiche() const{
<<<<<<< HEAD
  std::cout<<getNom()<< "de latitude: "<<getLat()<<" et de longitude: "<<getLon() <<std::endl;
=======
  std::list<Ligne<Moyens>*>::const_iterator it;
  std::cout<<getNom()<< "de latitude: "<<getLat()<<" et de longitude: "<<getLon()<<" de temps moyen d'attente pour une correspondance: "<<getTMC()<<" . Voici sa desserte:" <<std::endl;
  for (it = liaison.begin(); it != liaison.end(); it++)
  {
    std::cout << (*it)->getMoyen().getType()<<" qui va de "<<(*it)->getOrigin()->getNom()<<" a "<<(*it)->getDestination()->getNom()<<"\n"<<std::endl;
  }

>>>>>>> 75729ab300005806412176aa6d59f2b42fc7f585
}

void Terminal::ajoutLigne(Ligne<Moyens>* l, int f){}


void Terminal::suppLigne(Ligne<Moyens>* l)
{
  liaison.remove(l);
}
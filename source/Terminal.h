#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>
#include <string>
#include <list>
#include<cmath>

class Terminal{

protected:
  double latitude;
  double longitude;
  std::list<Terminal*> liaison;
  std::list<double> tempsMoyenCorrespondance;
  std::list<int> flux;

public:
  Terminal();
  Terminal(double lat, double lon);
  ~Terminal();
  const double getLat();
  const double getLon();
  const std::list<double> getTMC();
  const std::list<double> getFlux();
  const std::list<Terminal*> getLiaison();
  void setLat(double lat);
  void setLon(double lon);
  void setTMC(std::list<double> l);
  void setFlux(std::list<int> f);
  double distance(double lat, double lng);

};



#endif

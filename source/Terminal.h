#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>
#include <string>
#include <list>
#include<cmath>
#include "Ligne.h"

class Terminal{

  protected:
    double latitude;
    double longitude;
    std::list<Ligne<Terminal>*> liaison;
    std::list<double> tempsMoyenCorrespondance;
    std::list<int> flux;
    std:: string nom;

  public:
    Terminal();
    Terminal(double lat, double lon);
    ~Terminal();
    const double getLat() const;
    const double getLon() const;
    const std::list<double> getTMC() const;
    const std::list<int> getFlux() const;
    const std::list<Ligne<Terminal>*> getLiaison() const;
    void ajouterLiaison(Terminal t);
    void setLat(double lat);
    void setLon(double lon);
    void setTMC(std::list<double> l);
    void setFlux(std::list<int> f);
    double distance(double lat, double lng);
    const std::string getNom();
    void setNom(std::string n);
};



#endif

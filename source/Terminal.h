#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>
#include <string>
#include <list>
#include<cmath>
#include "Moyens.h"
#include "Ligne.h"
/*template <class T>
class Ligne;
*/
class Terminal{

  protected:
    double latitude;
    double longitude;
    std::list<Ligne<Moyens>*> liaison;
    double tempsMoyenCorrespondance;
    std::list<int> flux;
    std:: string nom;

  public:
    Terminal();
    Terminal(double lat, double lon, double t, std::string n);
    virtual ~Terminal();
    double getLat() const;
    double getLon() const;
    double getTMC() const;
    const std::list<int> getFlux() const;
    const std::list<Ligne<Moyens>*> getLiaison() const;
    void setLat(double lat);
    void setLon(double lon);
    void setTMC(double l);
    void setFlux(std::list<int> f);
    double distance(double lat, double lng);
<<<<<<< HEAD
    const std::string getNom()const;
=======
    std::string getNom() const;
>>>>>>> 75729ab300005806412176aa6d59f2b42fc7f585
    void setNom(std::string n);
    void affiche()const;
    virtual void ajoutLigne(Ligne<Moyens>* l, int f=0);
    void suppLigne(Ligne<Moyens>* l);
};
//


#endif

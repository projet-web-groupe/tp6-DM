#ifndef SCENARIO_H
#define SCENARIO_H

#include "Terminal.h"
#include "Voyage.h"
#include <list>

enum ville_e{
	Bruxelles = 0,
	Paris = 1,
	Lyon = 2,
	Rome = 3,
	Naple = 4
};
enum typeLien_e{
	NONE,
	TRAIN,
	AVION,
	AVIONELECTRIQUE
};
class Scenario {
	enum typeLien_e M[5][5];
	Terminal Term[5];
	std::list<Ligne<Moyens> *> l;
	Voyage *v[5][5];
	void ajouterLienMatrice(enum ville_e, enum ville_e,enum typeLien_e);
	void buildVoyage(void);
public:
	static ville_e ville;
	static typeLien_e typeLien;
	static int flux[5][5];
	static void afficherFlux();
	Scenario(int id);
	~Scenario();
	void afficherMatrice(void)const;


};

#endif
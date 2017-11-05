#include "Scenario.h"

#include "Terminal.h"
#include "AeroportInternational.h"
#include "AeroportRegional.h"
#include "Gare.h"
#include "HubAeroport.h"
#include "HubMultimodal.h"
#include "Train.h"
#include "Avion.h"
#include "AvionElec.h"
#include "Voyage.h"
#include <iostream>
#include <list>
#include <queue>

enum ville_e Scenario::ville;
enum typeLien_e Scenario::typeLien;

int Scenario::flux[5][5] = {
	{0		,13000	,5500	,4500	,2000},
	{12500	,0		,18000	,10000	,4000},
	{6000	,19000	,0		,6500	,2500},
	{5000	,9000	,6000	,0		,11000},
	{2500	,5000	,3000	,10000	,0}
};

void Scenario::afficherFlux(){
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			std::cout << flux[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Scenario::Scenario(int id){
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			M[i][j] =  NONE;
		}
	}
	switch (id){
		case 1:
		Term[Paris] = HubAeroport();
		Term[Bruxelles] = AeroportRegional();
		Term[Lyon] = AeroportInternational();
		Term[Rome] = AeroportRegional();
		Term[Naple] = AeroportRegional();
		ajouterLienMatrice(Paris,Lyon,AVION);
		ajouterLienMatrice(Rome,Naple,AVION);
		ajouterLienMatrice(Rome,Paris,AVION);
		ajouterLienMatrice(Paris,Bruxelles,AVION);
		break;
		case 2:
		Term[Paris] = HubMultimodal();
		Term[Bruxelles] = Gare();
		Term[Lyon] = AeroportRegional();
		Term[Rome] = AeroportInternational();
		Term[Naple] = AeroportRegional();

		ajouterLienMatrice(Naple,Rome,AVION);
		ajouterLienMatrice(Rome,Paris,AVION);
		ajouterLienMatrice(Paris,Lyon,AVION);
		ajouterLienMatrice(Paris,Bruxelles,TRAIN);
		break;
		case 3:
		Term[Paris] = HubMultimodal();
		Term[Bruxelles] = Gare();
		Term[Lyon] = Gare();
		Term[Rome] = HubMultimodal();
		Term[Naple] = Gare();

		ajouterLienMatrice(Naple,Rome,TRAIN);
		ajouterLienMatrice(Rome,Lyon,TRAIN);
		ajouterLienMatrice(Lyon,Paris,TRAIN);
		ajouterLienMatrice(Bruxelles,Paris,TRAIN);

		break;
		case 4:
		Term[Paris] = AeroportInternational();
		Term[Naple] = AeroportInternational();
		Term[Bruxelles] = AeroportInternational();
		Term[Rome] = AeroportInternational();
		Term[Lyon] = AeroportInternational();

		for (int i = 0; i < 5; ++i){
			for (int j = 0; j < 5; ++j){
				M[i][j] =  AVION;
			}
		}
		for (int j = 0; j < 5; ++j){
			M[j][j] =  NONE;
		}
		break;
		case 5:
		Term[Paris] = Gare();
		Term[Naple] = Gare();
		Term[Bruxelles] = Gare();
		Term[Rome] = Gare();
		Term[Lyon] = Gare();

		ajouterLienMatrice(Bruxelles,Paris,TRAIN);
		ajouterLienMatrice(Paris,Lyon,TRAIN);
		ajouterLienMatrice(Lyon,Rome,TRAIN);
		ajouterLienMatrice(Rome,Naple,TRAIN);
		break;
		case 6:
		Term[Paris] = HubAeroport();
		Term[Naple] = AeroportInternational();
		Term[Bruxelles] = AeroportInternational();
		Term[Rome] = AeroportInternational();
		Term[Lyon] = AeroportInternational();

		ajouterLienMatrice(Paris,Lyon,TRAIN);
		ajouterLienMatrice(Paris,Rome,TRAIN);
		ajouterLienMatrice(Paris,Naple,TRAIN);
		ajouterLienMatrice(Paris,Bruxelles,TRAIN);
		break;
	}
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			Ligne<Moyens> *ligne = NULL;
			switch(M[i][j]){
				case TRAIN:
				ligne = new Ligne<Moyens>(Train(),Term + i, Term + j);
				l.push_front(ligne);
				Term[i].ajoutLigne(ligne);
				break;
				case AVION:
				ligne = new Ligne<Moyens>(Avion(),Term + i, Term + j);
				l.push_front(ligne);
				Term[i].ajoutLigne(ligne);
				break;
				case AVIONELECTRIQUE:
				ligne = new Ligne<Moyens>(AvionElec(),Term + i, Term + j);
				l.push_front(ligne);
				Term[i].ajoutLigne(ligne);
			}
		}
	}
	buildVoyage();
}

Scenario::~Scenario(){
	while(!l.empty()){
		delete l.front();
		l.pop_front();
	}
}

void Scenario::buildVoyage(void){
	bool marque[5];
	std::list<enum ville_e> li;
	for (int i = 0; i < 5; ++i)
	{
		marque[0] = false;
		marque[1] = false;
		marque[2] = false;
		marque[3] = false;
		marque[4] = false;
		li.push_back((enum ville_e)i);
		marque[i] = true;


		while(!li.empty()){
			//on considère que le graphe parcourut est connexe
			int j = 0;
			while((M[li.back()][j] == NONE || marque[j]) && j < 5) {
				j++;
				/*switch(M[li.back()][j]){
					case TRAIN:
					printf("debug : (%i,%i) = Train (%s)\n",li.back(),j,(marque[j])?"true":"false");
					break;
					case AVION:
					printf("debug : (%i,%i) = Avion (%s)\n",li.back(),j,(marque[j])?"true":"false");
					break;
					case AVIONELECTRIQUE:
					printf("debug : (%i,%i) = AvionElec (%s)\n",li.back(),j,(marque[j])?"true":"false");
					break;
					default:
					printf("debug : (%i,%i) = none (%s)\n",li.back(),j,(marque[j])?"true":"false");
				}*/
			}
			if(j == 5){
				li.pop_back();
			}
			else{
				li.push_back((enum ville_e)j);
				marque[j] = true;
				v[li.front()][li.back()] = new Voyage(Term[li.front()],Term[li.back()]);
				for(std::list<enum ville_e>::iterator it = li.begin() ; it != li.end();){
					Ligne<Moyens> *ligne = NULL;
					switch(M[li.front()][li.back()]){
						case TRAIN:
						ligne = new Ligne<Moyens>((Moyens)Train(),&Term[*it],&Term[*(++it)]);
						v[li.front()][li.back()]->addCorrespondance(ligne);
						break;
						case AVION:
						ligne = new Ligne<Moyens>((Moyens)Avion(),&Term[*it],&Term[*(++it)]);
						v[li.front()][li.back()]->addCorrespondance(ligne);
						break;
						case AVIONELECTRIQUE:
						ligne = new Ligne<Moyens>((Moyens)AvionElec(),&Term[*it],&Term[*(++it)]);
						v[li.front()][li.back()]->addCorrespondance(ligne);
						break;
						default:
						ligne = new Ligne<Moyens>((Moyens)AvionElec(),&Term[*it],&Term[*(++it)]);
					}
					delete ligne;
				}
			}
		}
	}
}


void Scenario::ajouterLienMatrice(ville_e v1, ville_e v2,typeLien_e l){
	M[v1][v2] = l;
	M[v2][v1] = l;
}

void Scenario::afficherMatrice(void)const{
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			std::cout << M[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
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
		Term[Paris] = HubAeroport(48.8534,2.2488,0,"Paris");
		Term[Bruxelles] = AeroportRegional(50.8466,4.3528,0,"Bruxelles");
		Term[Lyon] = AeroportInternational(45.75,4.85,0,"Lyon");
		Term[Rome] = AeroportRegional(41.098251,12.492373,0,"Rome");
		Term[Naple] = AeroportRegional(40.854294,14.305573,0,"Naple");
		ajouterLienMatrice(Paris,Lyon,AVION);
		ajouterLienMatrice(Rome,Naple,AVION);
		ajouterLienMatrice(Rome,Paris,AVION);
		ajouterLienMatrice(Paris,Bruxelles,AVION);
		break;
		case 2:
		Term[Paris] = HubMultimodal(48.8534,2.2488,0,"Paris");
		Term[Bruxelles] = Gare(50.8466,4.3528,0,"Bruxelles");
		Term[Lyon] = AeroportRegional(45.75,4.85,0,"Lyon");
		Term[Rome] = AeroportInternational(41.098251,12.492373,0,"Rome");
		Term[Naple] = AeroportRegional(40.854294,14.305573,0,"Naple");

		ajouterLienMatrice(Naple,Rome,AVION);
		ajouterLienMatrice(Rome,Paris,AVION);
		ajouterLienMatrice(Paris,Lyon,AVION);
		ajouterLienMatrice(Paris,Bruxelles,TRAIN);
		break;
		case 3:
		Term[Paris] = HubMultimodal(48.8534,2.2488,0,"Paris");
		Term[Bruxelles] = Gare(50.8466,4.3528,0,"Bruxelles");
		Term[Lyon] = Gare(45.75,4.85,0,"Lyon");
		Term[Rome] = HubMultimodal(41.098251,12.492373,0,"Rome");
		Term[Naple] = Gare(40.854294,14.305573,0,"Naple");

		ajouterLienMatrice(Naple,Rome,TRAIN);
		ajouterLienMatrice(Rome,Lyon,TRAIN);
		ajouterLienMatrice(Lyon,Paris,TRAIN);
		ajouterLienMatrice(Bruxelles,Paris,TRAIN);

		break;
		case 4:
		Term[Paris] = AeroportInternational(48.8534,2.2488,0,"Paris");
		Term[Bruxelles] = AeroportInternational(50.8466,4.3528,0,"Bruxelles");
		Term[Lyon] = AeroportInternational(45.75,4.85,0,"Lyon");
		Term[Rome] = AeroportInternational(41.098251,12.492373,0,"Rome");
		Term[Naple] = AeroportInternational(40.854294,14.305573,0,"Naple");

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
		Term[Paris] = Gare(48.8534,2.2488,0,"Paris");
		Term[Bruxelles] = Gare(50.8466,4.3528,0,"Bruxelles");
		Term[Lyon] = Gare(45.75,4.85,0,"Lyon");
		Term[Rome] = Gare(41.098251,12.492373,0,"Rome");
		Term[Naple] = Gare(40.854294,14.305573,0,"Naple");

		ajouterLienMatrice(Bruxelles,Paris,TRAIN);
		ajouterLienMatrice(Paris,Lyon,TRAIN);
		ajouterLienMatrice(Lyon,Rome,TRAIN);
		ajouterLienMatrice(Rome,Naple,TRAIN);
		break;
		case 6:
		Term[Paris] = HubAeroport(48.8534,2.2488,0,"Paris");
		Term[Bruxelles] = AeroportInternational(50.8466,4.3528,0,"Bruxelles");
		Term[Lyon] = AeroportInternational(45.75,4.85,0,"Lyon");
		Term[Rome] = AeroportInternational(41.098251,12.492373,0,"Rome");
		Term[Naple] = AeroportInternational(40.854294,14.305573,0,"Naple");

		ajouterLienMatrice(Paris,Lyon,TRAIN);
		ajouterLienMatrice(Paris,Rome,TRAIN);
		ajouterLienMatrice(Paris,Naple,TRAIN);
		ajouterLienMatrice(Paris,Bruxelles,TRAIN);
		break;
	}
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			Ligne<Moyens> *ligne = NULL;
			puts("debug");
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
	buildVoyage(id);
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

void Scenario::affiche(void)const{
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			if(v[i][j] != NULL){
				v[i][j]->affiche();
			}
			//std::cout << v[i][j] << "\t";

			//std::cout<< "--"<<i+j<<"--"<< v[i][j] << std::endl;
		}
		std::cout << std::endl;
	}
}

void Scenario::buildVoyage(int id){
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			if (i != j){
				v[i][j] = new Voyage(Term[i],Term[j]);
			}
			else{
				v[i][j] = NULL;
			}
		}
	}
	switch(id){
		case 1:
		ajouterLigneVoyage(Bruxelles,Paris,Bruxelles,Paris);
		
		ajouterLigneVoyage(Bruxelles,Lyon,Bruxelles,Paris);
		ajouterLigneVoyage(Bruxelles,Lyon,Paris,Lyon);

		ajouterLigneVoyage(Bruxelles,Rome,Bruxelles,Paris);
		ajouterLigneVoyage(Bruxelles,Rome,Paris,Rome);
		
		ajouterLigneVoyage(Bruxelles,Naple,Bruxelles,Paris);
		ajouterLigneVoyage(Bruxelles,Naple,Paris,Rome);
		ajouterLigneVoyage(Bruxelles,Naple,Rome,Naple);

		
		ajouterLigneVoyage(Paris,Lyon,Paris,Lyon);

		ajouterLigneVoyage(Paris,Rome,Paris,Rome);
		
		ajouterLigneVoyage(Paris,Naple,Paris,Rome);
		ajouterLigneVoyage(Paris,Naple,Rome,Naple);

		
		ajouterLigneVoyage(Lyon,Rome,Lyon,Paris);
		ajouterLigneVoyage(Lyon,Rome,Paris,Rome);

		ajouterLigneVoyage(Lyon,Naple,Lyon,Paris);
		ajouterLigneVoyage(Lyon,Naple,Paris,Rome);
		ajouterLigneVoyage(Lyon,Naple,Rome,Naple);

		
		ajouterLigneVoyage(Rome,Naple,Rome,Naple);

		break;
	}
}

void Scenario::ajouterLigneVoyage(enum ville_e o1, enum ville_e d1, enum ville_e o2, enum ville_e d2){
	Ligne<Moyens> *ligne = NULL;
	switch(M[o1][d1]){
		case TRAIN:
		ligne = new Ligne<Moyens>(Train(),Term + (int)o2, Term + (int)d2);
		v[o1][d1]->addCorrespondance(ligne);
		break;
		case AVION:
		ligne = new Ligne<Moyens>(Avion(),Term + (int)o2, Term + (int)d2);
		v[o1][d1]->addCorrespondance(ligne);
		break;
		case AVIONELECTRIQUE:
		ligne = new Ligne<Moyens>(AvionElec(),Term + (int)o2, Term + (int)d2);
		v[o1][d1]->addCorrespondance(ligne);
	}

	switch(M[d1][o1]){
		case TRAIN:
		ligne = new Ligne<Moyens>(Train(),Term + (int)d2, Term + (int)o2);
		v[d1][o1]->addCorrespondance(ligne);
		break;
		case AVION:
		ligne = new Ligne<Moyens>(Avion(),Term + (int)d2, Term + (int)o2);
		v[d1][o1]->addCorrespondance(ligne);
		break;
		case AVIONELECTRIQUE:
		ligne = new Ligne<Moyens>(AvionElec(),Term + (int)d2, Term + (int)o2);
		v[d1][o1]->addCorrespondance(ligne);
	}
}
#include "Scenario.h"

#include "Terminal.h"
#include "AeroportInternational.h"
#include "AeroportRegional.h"
#include "Gare.h"
#include "HubAeroport.h"
#include "HubMultimodal.h"
#include <iostream>

enum ville_e Scenario::ville;
enum typeLien_e Scenario::typeLien;

int Scenario::flux[5][5] = {
	{0		,13000	,5500	,4500	,2000},
	{12500	,0		,18000	,10000	,4000},
	{6000	,19000	,0		,6500	,2500},
	{5000	,9000	,6000	,0		,11000},
	{2500	,5000	,3000	,10000	,0}
};

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
			if(M[i][j] != NONE){
				Term[i].ajouterLiaison(Term[j]);
			}
		}
	}
}

void Scenario::ajouterLienMatrice(ville_e v1, ville_e v2,typeLien_e l){
	M[v1][v2] = l;
	M[v2][v1] = l;
}

void Scenario::afficherMatrice(void){
	for (int i = 0; i < 5; ++i){
		for (int j = 0; j < 5; ++j){
			std::cout << M[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
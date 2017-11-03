#include "Voyage.h"

Voyage::Voyage(const Terminal& _origin, const Terminal& _destination) 
: origin(_origin), destination(_destination){}

void Voyage::addCorrespondance(const Ligne<Moyens>& _correspondance){
	if ( _correspondance != NULL){
		correspondance.push_back(_correspondance);
		correspondance.sort(correspondance.begin->compare);
	}

}

Voyage::~Voyage(){};

unsigned double Voyage::getTime(unsigned long int flux) const{
	unsigned double duration = 0;
	double distance;
	double nbVoyage;
	for(auto it = correspondance.begin; it != correspondance.end(); it++){
		distance = it->getOrigin()->getDistance(it->getDetination()->getLat(),it->getDetination()->getLon());
		nbVoyage = ceil(flux/it->getMoyen().getCapacite());
		duration += nbVoyage * (distance/it->getMoyen()->getVitesse());
	}
	return duration;
}

unsigned double getEmpreinteCarbone(unsigned long int flux) const{
	unsigned double empreinte = 0;
	double nbVoyage;
	for(auto it = correspondance.begin; it != correspondance.end(); it++){
		nbVoyage = ceil(flux/it->getMoyen().getCapacite());
		empreinte += nbVoyage * it->getMoyen()->getEmpreinteCarbone();
	}
	return empreinte;
}
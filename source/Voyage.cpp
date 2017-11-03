#include "Voyage.h"
#include "Moyens.h"
#include "Terminal.h"

Voyage::Voyage(const Terminal& _origin, const Terminal& _destination) 
: origin(_origin), destination(_destination){}

void Voyage::addCorrespondance(const Ligne<Moyens>* _correspondance){
	if ( _correspondance != NULL){
		correspondance.push_back(_correspondance);
		correspondance.sort();
	}

}

Voyage::~Voyage(){}

double Voyage::getTime(unsigned long int flux) const{
	double duration = 0;
	double distance;
	double nbVoyage;
	for(std::list<const Ligne<Moyens> *>::const_iterator it = correspondance.begin(); it != correspondance.end(); it++){
		distance = (*it)->getOrigin()->distance((*it)->getDestination()->getLat(),(*it)->getDestination()->getLon());
		nbVoyage = ceil(flux/(*it)->getMoyen().getCapacite());
		duration += nbVoyage * (distance/(*it)->getMoyen().getVitesse());
	}
	return duration;
}

double Voyage::getEmpreinteCarbone(unsigned long int flux)const{
	double empreinte = 0;
	double nbVoyage;
	for(std::list<const Ligne<Moyens> *>::const_iterator it = correspondance.begin(); it != correspondance.end(); it++){
		nbVoyage = ceil(flux/(*it)->getMoyen().getCapacite());
		empreinte += nbVoyage * (*it)->getMoyen().getEmpreinteCarbone();
	}
	return empreinte;
}
#ifndef VOYAGE_H
#define VOYAGE_H

class Voyage {
	Moyens origin;
	Moyens destination;
	//pointeur car destruction d'un voyage != destruction 
	std::list<Ligne *> correspondance;
}

#endif
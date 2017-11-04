#ifndef TRAIN_H
#define TRAIN_H


#include "Moyens.h"

class Train : public Moyens{
public:
	Train();
	void affiche(void)const;
	std::string getType()const;
};

#endif
#ifndef VOYAGE_H
#define VOYAGE_H

class Voyage {
	Moyens origin;
	Moyens destination;
	std::list<Avion *> correspAvion;
	std::list<Train *> correspTrain;
	std::list<TrainElec *> correspTrainElec;
}

#endif
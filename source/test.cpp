/*#include <iostream>
class Terminal{};

template <class T>
class Ligne
{
	const T typeTransports;
	//Pointeur car relation d'aggregation (destruction d'une ligne != destruction terminal)
	Terminal *origin;
	Terminal *destination;
	//chaque ligne à une frequence (qui peut différer pour un même moyen de transports)
	const int frequence;
public:
	void affiche(void)const{
		std::cout << "Object : Ligne\n\tType de transport :" << typeTransports.getNom() << "\n\torigin : " << "recup origin" << "\n\tdestination : " << "recup dest" << "\n\t/Fréquence de desserte : " << frequence << std::endl;
	}
	const int getFrequence(void)const{return frequence;}
	Ligne
	(
		const T& _typeTransports,
		const Terminal* _origin,Terminal *_destination, 
		const int _frequence = 1)
	:
	typeTransports(_typeTransports), 
	origin(_origin),
	destination(_destination),
	frequence(_frequence)
	{}


};

int main()
{
	return 0;
}
*/
#include "Vaisseau.h"
#include <iostream>
using namespace std;

void Vaisseau::removeVaisseau() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << " ";
}

void Vaisseau::putVaisseau() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << char(94);
}

Vaisseau::Vaisseau()
{
	coord.setPositionX(20);
	coord.setPositionY(35);
	putVaisseau();
}

void Vaisseau::modifierPosition(char key)
{
	removeVaisseau();
	switch (key)
	{
	case 'k':	coord.setPositionX(coord.getPositionX() - 1);	break;
	case 'l':	coord.setPositionX(coord.getPositionX() + 1);
	}
	putVaisseau();
}










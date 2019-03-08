#include "Martien.h"

Martien::Martien(int type, int valeur) :ExtraTerrestre(type, valeur)
{
	jiggle = true;
}

void Martien::jiggleMartien()
{

	if (isAlive == true) {

		removeExtraTerrestre();

		if (jiggle)
			coord.setPositionX(coord.getPositionX() - 1);
		else
			coord.setPositionX(coord.getPositionX() + 1);

		jiggle = !jiggle;

		putExtraTerrestre();
	}
}

void Martien::goDown() {
	if (isAlive == true) {
		removeExtraTerrestre();
		coord.setPositionY(coord.getPositionY() + 1);
		putExtraTerrestre();
	}
}

void Martien::killMartien() {
	removeExtraTerrestre();
	isAlive = false;
}



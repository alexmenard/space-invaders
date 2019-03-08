#include "ExtraTerrestre.h"
#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

int ExtraTerrestre::nombreExtraTerrestre = 0;

ExtraTerrestre::ExtraTerrestre(int type, int valeur)
{
	nombreExtraTerrestre++;
	typeExtraTerrestre = type;
	valeurExtraTerrestre = valeur;
}

void ExtraTerrestre::reduireNombreExtraTerrestre()
{
	nombreExtraTerrestre--;
}

int ExtraTerrestre::getNombreExtraTerrestre()
{
	return nombreExtraTerrestre;
}

void ExtraTerrestre::resetNombreExtraTerrestre()
{
	nombreExtraTerrestre = 0;
}

void ExtraTerrestre::removeExtraTerrestre() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << " ";
}

void ExtraTerrestre::putExtraTerrestre() const
{
	coord.gotoXY(coord.getPositionX(), coord.getPositionY());
	cout << char(typeExtraTerrestre);
}

int ExtraTerrestre::ajouterPoints() const
{
	return valeurExtraTerrestre;
}

void ExtraTerrestre::resetExtraTerrestre()
{
	int v1 = rand() % 78 + 2;
	int v2 = rand() % 18 + 2;
	coord.setPositionX(v1);
	coord.setPositionY(v2);
	isAlive = true;
}



#pragma once
#include "Laser.h"

class TableauLaser : public Laser
{
	int nbLasers;
	int maxLasers;
	double* tab;

public:
	TableauLaser();
	~TableauLaser();
	void afficher();
	void moveLaser();
	void lancerLasers(double nombre);
};

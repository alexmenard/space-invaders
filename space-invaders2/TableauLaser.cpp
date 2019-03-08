#include <iostream>
#include "TableauLaser.h"
#include "Laser.h"

TableauLaser::TableauLaser()
{
	this->nbLasers = 0;
	this->maxLasers = 1;
	this->tab = new double[this->maxLasers];
}
TableauLaser::~TableauLaser()
{
	delete[] this->tab;
	tab[0] = NULL;
}
void TableauLaser::afficher()
{
	for (int i = 0; i < this->nbLasers; i++) {
		std::cout << this->tab[i] << std::endl;
	}
}
void TableauLaser::lancerLasers(double nombre)
{
	if (this->nbLasers == this->maxLasers) {
		double* temp = new double[this->maxLasers * 2];
		for (int i = 0; i < this->nbLasers; i++) {
			temp[i] = this->tab[i];
		}
		delete[] this->tab;
		this->tab = temp;
		this->maxLasers *= 2;
	}
	this->tab[this->nbLasers] = nombre;
	this->nbLasers++;
}

void TableauLaser::moveLaser()
{
	removeLaser();
	if (coord.getPositionY() > 0)
	{
		coord.setPositionY(coord.getPositionY() - 1);
		putLaser();
	}
	else
		isAlive = false;
}
#pragma once
#include"Vaisseau.h"
#include"Laser.h"

class Partie
{
	Vaisseau* vaisseau;
	Laser* laser;
	void calculerDirection(char touche, int& x, int& y);
	void boucleDeVie();
	int recupereTouche();

public:
	Partie();
	~Partie();
	void lancerPartie();
	void afficherTerrain(int nbLignes, int nbColonnes);
};


#pragma once

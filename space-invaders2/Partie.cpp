#include "Partie.h"
#include "Vaisseau.h"
#include "Martien.h"
#include "UIKit.h"
#include"laser.h"
#include <time.h>
#include <iostream>
#include <conio.h>
#include <optional>

Partie::Partie()
{

}
void Partie::calculerDirection(char touche, int& x, int& y)
{
	if (touche == 'k') {
		//Je vais vers la gauche
		x--;
	}
	else if (touche == 'l') {
		//Je vais vers la droite
		x++;
	}
}

void Partie::boucleDeVie()
{
	int x = 5;
	int y = 5;
	int tour = 0;
	int type = 43;
	int valeur = 5;
	bool aGagner = false;
	bool aPerdu = false;
	int touchePresse;
	this->vaisseau = new Vaisseau;
	this->laser = new Laser;
	Martien* tabMartien[10];

	UIKit::curseurVisible(false);

	for (int i = 0; i < 10; i++) {
		tabMartien[i] = new Martien(type, valeur);
		tabMartien[i]->resetExtraTerrestre();
		tabMartien[i]->putExtraTerrestre();
	}

	do {

		tour++;
		touchePresse = recupereTouche();

		if ((this->vaisseau->coord.getPositionX() > 2 && touchePresse == 'k') || (this->vaisseau->coord.getPositionX() < 98 && touchePresse == 'l'))
		{
			this->vaisseau->modifierPosition(touchePresse);
		}

		if (touchePresse == 32) {
			if (!this->laser->isAlive) {
				this->laser->startLaser(this->vaisseau->coord.getPositionX());
			}
			else {
				this->laser->moveLaser();
			}
		}
		if (this->laser->isAlive) {
			this->laser->moveLaser();
		}

		if (this->laser->coord.getPositionY() == 1) {
			this->laser->removeLaser();
			this->laser->killLaser();
		}

		//verifie si contact entre laser et martien
		for (int i = 0; i < 10; i++)
		{
			if (this->laser->coord.getPositionX() == tabMartien[i]->coord.getPositionX() &&
				this->laser->coord.getPositionY() == tabMartien[i]->coord.getPositionY()) {

				this->laser->removeLaser();
				this->laser->killLaser();
				tabMartien[i]->reduireNombreExtraTerrestre();
				tabMartien[i]->removeExtraTerrestre();
				tabMartien[i]->killMartien();
				delete tabMartien[i];
			}
		}

		//cycle des martiens
		if (tour == 20 || tour == 40 || tour == 60) {
			for (int i = 0; i < 10; i++)
			{
				tabMartien[i]->jiggleMartien();
			}
		}
		if (tour == 80) {
			for (int i = 0; i < 10; i++)
			{
				if (tabMartien[i]->coord.getPositionY() == this->vaisseau->coord.getPositionY()) {
					aPerdu = true;
				}
				else {
					tabMartien[i]->goDown();
				}
			}
			tour = 0;
		}

		Sleep(20);

		if (Martien::getNombreExtraTerrestre() == 0) {
			aGagner = true;
		}

	} while (aGagner == false && touchePresse != 27 && aPerdu == false);

	if (aGagner == true)
	{
		system("cls");
		cout << "	__      _(_)_ __  _ __   ___ _ __  | |" << endl;
		cout << "	\\ \\ /\\ / / | '_ \\| '_ \\ / _ \\ '__| | |" << endl;
		cout << "	 \\ V  V /| | | | | | | |  __/ |    |_|" << endl;
		cout << "	  \\_/\\_/ |_|_| |_|_| |_|\\___|_|    (_)" << endl;
		system("pause");
	}
	if (aPerdu == true) {
		system("cls");
		cout << " _ _   |_  _  _| " << endl;
		cout << "_)(_)  |_)(_|(_|... " << endl;
		system("pause");
	}

	_getch();
}

int Partie::recupereTouche() {
	if (_kbhit() != 0) {
		return _getch();
	}
	return -1;
}

void Partie::lancerPartie()
{
	Partie::boucleDeVie();
}
Partie::~Partie()
{
	delete vaisseau;
	delete laser;
}

void Partie::afficherTerrain(int nbLignes, int nbColonnes) {

	UIKit::setDimensionFenetre(0, 0, 80, 41);
	UIKit::cadre(0, 0, 80, 40, 2);
	UIKit::curseurVisible(false);
}



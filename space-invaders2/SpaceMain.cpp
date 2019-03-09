#include <conio.h>
#include <time.h>
#include <iostream>
#include "UIKit.h"
#include "Partie.h"
#include "Vaisseau.h"

using namespace std;

void afficherMenu();

void main()
{
	//afficherMenu();
	Partie partie;
	partie.afficherTerrain(70, 30);
	partie.lancerPartie();

}

void afficherMenu()
{

}








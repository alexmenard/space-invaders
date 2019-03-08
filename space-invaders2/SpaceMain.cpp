#include <conio.h>
#include <time.h>
#include <iostream>
#include "UIKit.h"
#include "Partie.h"
#include "Vaisseau.h"

using namespace std;

void main()
{
	Partie partie;
	partie.afficherTerrain(70, 30);
	partie.lancerPartie();

}

void afficherMenu()
{
	system("cls");

	cout << "          ___  ___  ___  ___  ___  " << endl;
	cout << "         / __>| . \| . ||  _>| __> " << endl;
	cout << "         \__ \|  _/|   || <__| _> " << endl;
	cout << "         <___/|_|  |_|_|`___/|___> " << endl << endl << endl;

	cout << "       _  _ _  _ _  ___  ___  ___  ___ " << endl;
	cout << "      | || \ || | || . || . \| __>| . \ " << endl;
	cout << "      | ||   || ' ||   || | || _> |   /" << endl;
	cout << "      |_||_\_||__/ |_|_||___/|___>|_\_\ " << endl;

}








#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <Windows.h>

#include "UtilitairesES.h"

void lireFichier(list<string> &listFichier);

using namespace std;

int main() {

	list<string> * listFichier = new list<string>();
	lireFichier(*listFichier);
	int choixPrincipale = 1;

	while (choixPrincipale != 0) {

		choixPrincipale = lireEntier("1) Jouer une partie\n2) Quitter\nFaites votre choix", 0, 2);

		switch (choixPrincipale) {
		case 0:
			return 0;
			break;
		case 1:

			break;
		}
		

	}

	system("pause");
	return 0;
}

void JeuQuestion() {

}

/*
 * Lire le fichier afin de créer la liste
 */
void lireFichier(list<string> &listFichier) {
	 ifstream fichier("liste.txt", ios::in);
		string ligne;
		 
		while (!fichier.eof())  // tant que l'on peut mettre la ligne dans "contenu"
		{
			getline(fichier, ligne);
			listFichier.push_back(ligne);
			cout << ligne << endl;  // on l'affiche
		}

		fichier.close();
}
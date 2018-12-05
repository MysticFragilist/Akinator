#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <Windows.h>

#include "UtilitairesES.h"
#include "Tree.h"

void JeuQuestion(Tree<string>& tree);
void lireFichier(list<string> &listFichier);

using namespace std;

int main() {
	Tree<string>* tree = new Tree<string>();
	list<string> * listFichier = new list<string>();

	//read the file and insert it in the list
	lireFichier(*listFichier);

	//Construct with the list
	tree->Construct(*listFichier);
	int choixPrincipale = 1;

	setlocale(LC_ALL, "");

	while (choixPrincipale != 0) {

		choixPrincipale = lireEntier("1) Jouer une partie\n2) Quitter\nFaites votre choix", 1, 2);

		switch (choixPrincipale) {
		case 1:
			JeuQuestion(*tree);
			break;
		case 2:
			tree->save();
			return 0;
			break;
		}
		

	}

	system("pause");
	return 0;
}

void JeuQuestion(Tree<string>& tree) {
	bool isFinished = false;
	tree.moveCursorRoot();

	while (!isFinished) {
		if (tree.isCursorValid()) {
			if (!tree.isCursorLeaf()) {
				string question = tree.getCursorElement();
				bool statementIsTrue = lireOouN(question);

				if (statementIsTrue) {
					//it's a yes
					tree.moveCursorLeft();
				}
				else {
					//it's a no
					tree.moveCursorRight();
				}
			}
			else {
				string response = tree.getCursorElement();
				bool isTheAnswer = lireOouN("Trouvé c'est un " + response + "! Est-ce à quoi vous pensiez");

				if (isTheAnswer) {
					cout << "Youpiii j'ai trouvé!" << endl;
				}
				else {
					string newQuestion = lireString("Entrez une question pour m'aidez à le retrouver");
					string newResponse = lireString("Entrez ce à quoi vous pensiez");

					tree.AddElement(newQuestion, newResponse);
				}
				isFinished = true;
			}
		}
		else {
			cout << "je ne sais pas" << endl;
			string newQuestion = lireString("Entrez une question pour m'aidez à le retrouver");
			string newResponse = lireString("Entrez ce à quoi vous pensiez");

			tree.AddElement(newQuestion, newResponse);
			isFinished = true;

		}
		
	}
}

/*
 * Lire le fichier afin de creer la liste
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
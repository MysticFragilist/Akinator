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
/**
 * Program for the class of Structure de Donn�es in c++
 *
 * The goal of the TP is to make a simple akinator type game in a search tree,
 * The tree is realized using template class and list
 *
 * Author: Samuel Montambault
 * Date: 5 december 2018
 */
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
			tree->setNomFichier("liste.txt");
			tree->save();
			return 0;
			break;
		}
		

	}

	system("pause");
	return 0;
}

/**
 * The function in which the game take place
 * Each iteration, akinator naviguate throught the 
 * the tree and ask the question, narrowing the range of response possible
 *
 */
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
				//will enter here if the present node is a response node
				string response = tree.getCursorElement();
				bool isTheAnswer = lireOouN("Trouv� c'est un " + response + "! Est-ce � quoi vous pensiez");

				if (isTheAnswer) {
					cout << "Youpiii j'ai trouv�!" << endl;
				}
				else {
					string newQuestion = lireString("Entrez une question pour m'aidez � le retrouver");
					string newResponse = lireString("Entrez ce � quoi vous pensiez");

					tree.AddElement(newQuestion, newResponse);
				}
				isFinished = true;
			}
		}
		else {
			//if the cursor is actually nullptr 
			cout << "je ne sais pas" << endl;
			string newQuestion = lireString("Entrez une question pour m'aidez � le retrouver");
			string newResponse = lireString("Entrez ce � quoi vous pensiez");
			
			//adding the new element
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
			
		}

		fichier.close();
}
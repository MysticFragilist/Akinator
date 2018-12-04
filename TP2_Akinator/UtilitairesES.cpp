#include "UtilitairesES.h"
#include <iostream>


int lireEntier(const string& message, int limiteInferieure,
	int limiteSuperieure) {
	int nombre = 0;
	bool valide = false;
	while (!valide) {
		cout << message << ":";
		cin >> nombre;
		if (cin.fail()) {
			cerr << "Vous devez entrer une valeur réelle !!" << endl;
		}
		else if (nombre >= limiteInferieure && nombre <= limiteSuperieure) {
			valide = true;
		}
		else {
			cerr << "Vous devez entrer une valeur entre " << limiteInferieure << " "
				<< "et " << limiteSuperieure << "." << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
	return nombre;
}


float lireReel(const string& message, float limiteInferieure){
	float nombre = 0;
	bool valide = false;
	while (!valide) {
		cout << message << ":";
		cin >> nombre;
		if (cin.fail()) {
			cerr << "Vous devez entrer une valeur entière !!" << endl;
		}
		else if (nombre >= limiteInferieure) {
			valide = true;
		}
		else {
			cerr << "Vous devez entrer une valeur plus grande que "
				<< limiteInferieure << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
	return nombre;
}

bool lireOouN(const string& message) {
	string resp = "";
	bool valide = false;
	while (!valide) {
		cout << message << " (O/N) ? ";
		cin >> resp;

		if (cin.fail() || (resp != "O" && resp != "N")) {
			cerr << "Vous devez entrer une O pour oui ou N pour non." << endl;
			valide = false;
		}
		else 
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}


	return resp == "O";
}

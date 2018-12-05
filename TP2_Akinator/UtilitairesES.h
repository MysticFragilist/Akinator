#ifndef UTILITAIRES_ES
#define UTILITAIRES_ES

/**
* Fichier qui comporte des fonctions permettant de faciliter les
* entr�es/sorties
*
* Auteur: �ric Wenaas
* Date  : 6 septembre 2016
*/

#include <string>

using namespace std;

/**
* Permet de lire un entier entre limiteInferieure et limiteSuperieure
*
* Entr�e: message Le message qui sera affich� � chaque lecture
* Entr�e: limiteInferieure la limite inf�rieure
* Entr�e: limiteSuperieure la limite sup�rieure
* Sortie: la valeur enti�re lue entre limiteInferieure et limiteSuperieure
*/
int lireEntier(const string& message, int limiteInferieure,
	int limiteSuperieure);

/**
* Permet de lire un r�el entre limiteInferieure et limiteSuperieure
* exclusivement
*
* Entr�e: message Le message qui sera affich� � chaque lecture
* Entr�e: limiteInferieure la limite inf�rieure
* Entr�e: limiteSuperieure la limite sup�rieure
* Sortie: la valeur r�elle lue entre limiteInferieure et limiteSuperieure
*/
float lireReel(const string& message, float limiteInferieure);

/**
* Permet de lire un caract�re O ou N pour une question vrai ou faux
*
* Entr�e: message Le message qui sera affich� � chaque lecture
* Sortie: true if it's a yes false if it's a no
*/
bool lireOouN(const string& message);

/**
* Permet de lire un chaine de caract�re � l'�cran
*
* Entr�e: message Le message qui sera affich� � chaque lecture
* Sortie: string entr�e
*/
string lireString(const string& message);
#endif
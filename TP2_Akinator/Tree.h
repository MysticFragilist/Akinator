#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

template<typename T> 
class Tree {
public:

	/**
	* An empty constructor which call the 
	*/
	Tree() {
		root = cursor = nullptr;
		size = 0;
		nomFichier = "";
	}

	/**
	* A constructor to set the root element at first
	*/
	Tree(T element) {
		root = cursor = new Node<T>(element);
		size = 1;
		nomFichier = "";
	}

	Tree& operator=(const Tree& tree) {
		tree.moveCursorRoot();
		cursor = root;


	}

	/**
	* A copied Constructor
	*/
	Tree(const Tree& p) {
		*this = p;
	}

	~Tree() {

	}

	const Tree<T>& operator=(const Tree<T>& original) {


	}

	void Construct(list<T> list) {
		//start the recursion
		ConstructRecursif(root, 0,"R", list);
	}


	void AddElement(T element) {
		
	}

	/**
	 * Put the cursor at his child to his left
	 */
	const void moveCursorLeft() {
		cursor = cursor->getLeftNode();
	}

	/**
	 * Put the cursor at his child to his right
	 */
	const void moveCursorRight() {
		cursor = cursor->getRightNode();
	}

	/**
	 * Put the cursor at the root of the tree
	 */
	const void moveCursorRoot() {
		cursor = root;
	}

	
	/**
	 * return the number node
	 */
	int getSize() {
		return size;
	}
	
	Node<T> getRoot() const {
		return root;
	}

	void setNomFichier(string nomFic) {
		this->nomFichier = nomFic;
	}

	//The method to call where you must call saveRecursif
	void save() {
		ofstream stream;
		stream.open(nomFichier, fstream::out);
		stream.close();

		sauvegarderRecursif(root, "R", 0);
	}

private:
	
	//Empty all the subTree by the node pass in argument
	//It will clear all node below the one entered
	void DestroyTreeRecursion(Node<T>* n) {

		if (n->gauche != nullptr) {
			EmptyTreeRecursion(n->gauche);
		}
		if (n->droite != nullptr) {
			EmptyTreeRecursion(n->droite);
		}

		delete n;
		
	}

	void ConstructRecursif(Node<T> *&n, int level, string position, list<string> &list) {

		//Verify if the list is empty
		if (!list.empty()) {
			T line = list.front();

			//Initialiser les variables
			int listLevel = stoi(line.substr(0, 1).c_str(), 0);
			string listPos = line.substr(2, 1);


			//If it's root then 
			if (level == listLevel && position == listPos) {

				string listContent = list.pop_front();
				n = new Noeud();
				n->setElement(listContent);
				size ++;

				ConstructRecursif(n->leftNode, level + 1, "G", list);
				ConstructRecursif(n->rightNode, level + 1, "D", list);
			}
		}

	}
	//sauvegarder en naviguant en mode pr�fixe
	void saveRecursif(Node<T> * n, string direction, int level) {
		
		
		if (n != nullptr) {
			ofstream stream;
			stream.open(nomFichier, ios::app);
			stream << level << "\t" << direction << "\t" << n->getElement();
		}

		saveRecursif(n->leftNode, "L", level + 1);
		saveRecursif(n->rightNode, "R", level + 1);

	}

	Node<T>* cursor;
	Node<T>* root;
	string nomFichier;
	int size;
};
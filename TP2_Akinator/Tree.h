#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

template<typename T> 
class Tree {
public:
	enum TypeNaviguation {
		prefixe, infixe, postfixe
	};


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
		initializeRecur();
	}

	Tree& operator=(const Tree& tree) {
		tree.moveCursorRoot();

	}


	//needed to initialize when operator= is called
	//or when copied constructor is called 
	Node* initializeRecur(Noeud *n) {

		Node* newNode = nullptr;

		if (n != nullptr) {
			newNode = new Node();

			newNode->element = n->element;
			newNode->leftNode = initializeRecu(n->leftNode);
			newNode->rightNode = initializeRecu(n->rightNode);
		}
		return newNode;
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
		
	}


	void AddElement(T element) {
		
	}

	void AddLeftElementCursor(const T elem) {

		Node<T> * nouveau = new Node<T>(elem);
		cursor->setLeftNode(nouveau);
		size++;
	}

	void AddRightElementCursor(const T elem) {

		Node<T> * nouveau = new Node<T>(elem);
		cursor->setRightNode(nouveau);
		size++;
	}

	const void moveCursorLeft() {
		cursor = cursor->getLeftNode();
	}

	const void moveCursorRight() {
		cursor = cursor->getRightNode();
	}

	const void moveCursorRoot() {
		cursor = root;
	}

	

	int getSize() {
		return size;
	}
	
	Node<T> getRoot() const {
		return root;
	}

	void setNomFichier(string nomFic) {
		this->nomFichier = nomFic;
	}

	void ShowTree(TypeNaviguation Type) {
		

	}
	//The method to call where you must call saveRecursif
	void save() {
		ofstream stream;
		stream.open(nomFichier, fstream::out);
		stream.close();

		sauvegarderRecursif(root, "R", 0);
	}

private:
	void ConstructRecursif(Noeud *&n, int level, string position, list<string> &list) {

		//Verify if the list is empty
		if (!list.empty()) {
			T line = list.front();

			//Initialiser les variables
			int listLevel = stoi(line.substr(0, 1).c_str(), 0);
			string listPos = line.substr(2, 1);


			//If it's root then 
			if (level == listLevel && position == listPos) {

				string listContent = list.pop_front().substring;
				n = new Noeud();
				n->setElement(listContent);

				ConstructRecursif(n->leftNode, level + 1, "G", list);
				ConstructRecursif(n->rightNode, level + 1, "D", list);
			}
		}

	}
	//sauvegarder en naviguant en mode préfixe
	void saveRecursif(Node * n, string direction, int level) {
		
		
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
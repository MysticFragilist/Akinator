#pragma once
#include <iostream>
#include "Node.h"

template<typename T> class Tree {
public:

	enum TypeNaviguation { prefixe, infixe, postfixe };


	Tree(T element) {
		root = new Node<T>(element);
		cursor = root;
		size = 0;
	}

	Tree(const Tree& p) {
		*this = p;
	}

	~Tree() {
		
	}

	const Tree<T>& operator=(const Tree<T>& original) {


	}

	void rotationGauche(Node *& n) {
		Node * tmp = n->droite;
		n->droite = tmp->gauche;
		tmp->gauche = n;
		n = tmp;
	}
	void rotationDroite(Node *& n) {
		Node * tmp = n->gauche;
		n->gauche = tmp->droite;
		tmp->droite = n;
		n = tmp;
	}
	void rotationGaucheDroite(Node *& n) {
		rotationGauche(n->gauche);
		rotationDroite(n);
	}
	void rotationDroiteGauche(Node *& n) {
		rotationDroite(n->droite);
		rotationGauche(n);
		
	}
	void AddElement(T element) {
		Node * n = new Node();

		n->setElement(elem);
		if (root == nullptr) {

		}
		else {
			bool place = false;
			Node* tmp = racine;
			while (!place) {
				if (elem < tmp->getElement()) {
					if (tmp->getGauche() == nullptr) {
						tmp->setGauche(n);
						place = true;

					}
					else
						tmp->gauche
				}
				else {
					if (tmp->getDroite() == nullptr) {
						tmp->setDroite(n);
						place = true;

					}
					else
						tmp->getDroite()
				}
			}
		}
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

	void moveCursorLeft() {
		cursor = cursor->getLeftNode();
	}

	void moveCursorRight() {
		cursor = cursor->getRightNode();
	}
	void moveCursorRoot() {
		cursor = root;
	}

	void ShowTree(TypeNaviguation Type) {
		
		naviguate(Type, root, &Tree::showNode);
	}

	int getSize() {
		return size;
	}
	
	Node<T> getRoot() const {
		return root;
	}

private:
	// params:
	// Type - prefixe, infixe, postfixe -
	// Node - le noeud actuel
	// traitement - la function de traitement à faire
	void naviguate(TypeNaviguation Type, Node<T>* n, void (Tree::*traitement)(Node<T>* n)) {
		switch (Type) {
		case prefixe:
			if (n != nullptr) {

				*traitement(n);
				naviguate(Type, n->getLeftNode(), &traitement);
				naviguate(Type, n->getRightNode(), &traitement);
			}
			break;
		case infixe:
			if (n != nullptr) {
				
				naviguate(Type, n->getLeftNode(), &traitement);
				traitement(n);
				naviguate(Type, n->getRightNode(), &traitement);
			}
			break;
		case postfixe:
			if (n != nullptr) {

				naviguate(Type, n->getLeftNode(), &traitement);
				naviguate(Type, n->getRightNode(), &traitement);
				traitement(n);
			}
			break;
		}
	}

	void showNode(Node<T>* n) {
		T elem = n->getElement();
		
		std::cout << elem << std::endl;
	}

	Node<T>* cursor;
	Node<T>* root;
	int size;
};
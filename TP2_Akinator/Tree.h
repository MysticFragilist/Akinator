#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

template<typename T> 
class Tree {
public:

	/**
	* An empty constructor
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


	/**
	* A copied Constructor
	*/
	Tree(const Tree& p) {
		*this = p;
	}

	/**
	* Destructor: empty the tree
	*/
	~Tree() {
		DestroyTreeRecursion(root);
	}

	/**
	* The operator= for the tree, copy each node and put them 
	* accordingly.
	*/
	const Tree<T>& operator=(const Tree<T>& original) {
		original.moveCursorRoot();
		cursor = root;

		//to fill
		root = construireRecursif(original.root);

	}
	
	Node<T>* construireRecursif(Node<T> *n) {
		Node<T>* nouveau = nullptr;
		if (n != nullptr) {
			nouveau = new Node<T>();
			nouveau->element = n->element;
			nouveau->leftNode = construireRecursif(n->leftNode);
			nouveau->rightNode = construireRecursif(n->rightNode);
		}
		return nouveau;
	}

	/**
	* Construct the tree with the list
	*/
	void Construct(list<T>& list) {
		//start the recursion
		ConstructRecursif(root, 0,"R", list);
	}

	/**
	 * Add the element pass in parameter
	 */
	void AddElement(T question, T response) {

		if (cursor == nullptr) {
			
			//find the last node
			Node<T>* cursorPrec = root;
			bool isFinished = false;

			while (!isFinished) {
				if (cursorPrec->rightNode == nullptr) {
					isFinished = true;
				}
				else {
					cursorPrec = cursorPrec->rightNode;
				}
			}
			//cursorPrec contains now the preceding node of the cursor
			Node<T> *nQuestion = new Node<T>(question);
			Node<T> *nResponse = new Node<T>(response);

			cursorPrec->setRightNode(nQuestion);
			nQuestion->setLeftNode(nResponse);

			if (root == nullptr) {
				root = cursorPrec;
			}
		}
		else {
			Node<T> *oldResp = new Node<T>(cursor->getElement());
			Node<T> *newResp = new Node<T>(response);
			
			cursor->setElement(question);

			cursor->setLeftNode(newResp);
			cursor->setRightNode(oldResp);
		}
	}

	//The method to call where you must call saveRecursif
	void save() {
		ofstream stream;
		stream.open(nomFichier, fstream::out);
		stream.close();

		saveRecursif(root, "R", 0);
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
	* get the T element of the cursor 
	*/
	const T getCursorElement() const {
		return cursor->getElement();
	}

	/**
	 * return true if the cursor is a leaf (a response)
	 */
	const bool isCursorLeaf() const {
		return cursor->leftNode == nullptr && cursor->rightNode == nullptr;
	}

	/**
	* return true if the cursor is valid
	*/
	const bool isCursorValid() const {
		return cursor != nullptr;
	}

	/**
	 * return the number of node present in the tree
	 */
	const int getSize() const {
		return size;
	}

	void setNomFichier(string nomFic) {
		this->nomFichier = nomFic;
	}

private:
	
	//Empty all the subTree by the node pass in argument
	//It will clear all node below the one entered
	void DestroyTreeRecursion(Node<T>* n) {

		if (n != nullptr) {
			EmptyTreeRecursion(n->gauche);
			EmptyTreeRecursion(n->droite);
			delete n;
		}		
	}

	//Construct the tree as a recursive method from a list passed in parameter
	//
	//I know that the code use can't be used 
	void ConstructRecursif(Node<T> *&n, int level, string position, list<string> &list){
 
		//Verify if the list is empty
		if (!list.empty()) {
			T line = list.front();

			//Initialiser les variables
			int listLevel = stoi(line.substr(0, 1).c_str(), 0);
			string listPos = line.substr(2, 1);
			string listContent = line.substr(4, line.size() - 1);

			//check whether it's the right one to insert from the list
			if (level == listLevel && position == listPos) {

				list.pop_front();
				n = new Node<string>();
				n->setElement(listContent);
				size ++;

				//If it's root then set it
				if (root == nullptr) {
					root = n;
				}

				ConstructRecursif(n->leftNode, level + 1, "L", list);
				ConstructRecursif(n->rightNode, level + 1, "R", list);
			}
		}

	}

	//sauvegarder en naviguant en mode prefixe
	void saveRecursif(Node<T> * n, string direction, int level) {
		
		if (n != nullptr) {
			ofstream stream;
			stream.open(nomFichier, ios::app);
			stream << level << "\t" << direction << "\t" << n->getElement() << endl;
			
			saveRecursif(n->leftNode, "L", level + 1);
			saveRecursif(n->rightNode, "R", level + 1);
		}

		
	}

	Node<T>* cursor;
	Node<T>* root;
	string nomFichier;
	int size;
};
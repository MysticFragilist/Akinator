#pragma once
#include "Tree.h"

template<typename T>
class Node {

	template<typename T> friend class Tree;

public:

	/**
	 * An empty constructor
	 */
	Node()
	{
		rightNode = nullptr;
		leftNode = nullptr;
		this->m_item = T();
	}

	/**
	* A constructor fill with an element
	*/
	Node(T m_item) {
		this->m_item = m_item;
		rightNode = nullptr;
		leftNode = nullptr;
	}

	/**
	* the destructor
	*/
	~Node() {

	}

	/**
	* set the item of the Node
	*/
	void setElement(T value) {
		this->m_item = value;
	}

	/**
	* get the item of the Node
	*/
	T getElement() const {
		return m_item;
	}

	/**
	* get the child left node
	*/
	Node<T>* getLeftNode() const {
		return leftNode;
	}

	/**
	* set the child left node
	*/
	void setLeftNode(Node<T>* node) {
		leftNode = node;
	}

	/**
	* get the child right node
	*/
	Node<T>* getRightNode() const {
		return rightNode;
	}

	/**
	* set the child right node
	*/
	void setRightNode(Node<T>* node) {
		rightNode = node;
	}


private:
	// the element of the node!
	T m_item;

	//the cursor to the left child node
	Node<T> *leftNode;

	//the cursor to the right child node
	Node<T> *rightNode;
};
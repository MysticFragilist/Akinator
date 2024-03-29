#include "Node.h"

Node::Node()
{
	rightNode = nullptr;
	leftNode = nullptr;
	this->m_item = NULL;
}

Node(T m_item) {
	this->m_item = m_item;
	rightNode = nullptr;
	leftNode = nullptr;
}

~Node() {

}

void setElement(T value) {
	this->m_item = value;
}

T getElement() const {
	return m_item;
}

Node<T>* getLeftNode() const {
	return leftNode;
}

void setLeftNode(Node<T>* node) {
	leftNode = node;
}

Node<T>* getRightNode() const {
	return rightNode;
}

void setRightNode(Node<T>* node) {
	rightNode = node;
}

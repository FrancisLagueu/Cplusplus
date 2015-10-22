#include<iostream>
#include<string>
#include"BinarySearchTree.h"

using namespace std;



template<class T>
 BinarySearchTree<T>::~BinarySearchTree()
{
	DeleteTree(root);
}
 template<class T>
 void BinarySearchTree<T>::Insert(const T & item)
 {
	 Insert(root, item);
 }
template<class T>
Node BinarySearchTree<T>::findMin() {
	Node* node = this;
	while (node->left != NULL)
		node = node->left;
	return node;
}
template<class T>
Node BinarySearchTree<T>::findMax() {
	Node* node = this;
	while (node->right != NULL)
		node = node->right;
	return node;
}
template<class T>
Node BinarySearchTree<T>::find(Node *node, T item)
{
	if (node == NULL)
		return NULL;
	if (node != NULL) {
		if (item < node->data)
			return find(node->left, item);
		else if (item > node->data)
			return find(node - right, item);
		if (item == node->data)
			return node;
	}
}
template<class T>
void BinarySearchTree<T>::Delete(T &item)
{
	Delete(root, item);
}
template<class T>
void BinarySearchTree<T>::Insert(Node*& node, const T& item) {
	if (node == NULL)
		node = new Node(item);
	else if (item < node->data)
		Insert(node->left, item);
	else if (item > node->data)
		Insert(node->right, item);
}
template<class T>
void BinarySearchTree<T>::DeleteTree(Node *node)
{
	if (node != NULL) {
		DeleteTree(node->left);
		DeleteTree(node->right);
		delete node;
	}
}
template<class T>
void BinarySearchTree<T>::Delete(Node*&node, T &item)
{
	if (node == NULL)
		return;
	if (item < node->data)
		Delete(node->left, item);
	else if (item > node->data)
		Delete(node->right, item);
	else {
		Node* temp;
		if (node == NULL)
			return;
		else if (node->right == NULL) {
			temp = node;
			node = node->left;
			delete temp;
		}
		else if (node->left == NULL) {
			temp = node;
			node = node->right;
			delete temp;
		}
		else {
			Node* prev = node;
			temp = node->left;
			while (temp->right != NULL) {
				prev = temp;
				temp = temp->right;
			}
			node->data = temp->data;
			if (prev != node)
				prev->right = temp->left;
			else
				prev->left = temp->left;
			delete temp;
		}
	}
}
template<class T>
void BinarySearchTree<T>::Print(ostream &, Node *node) const
{
}
template<class T>
Node BinarySearchTree<T>::find(T item)
{
	return Node();
}
template<class T>
bool BinarySearchTree<T>::operator<(const T &item1, const T &item2)
{
	bool entry = false;
	if (item1 < item2)
		entry = true;
	
	return entry;
}
template<class T>
bool BinarySearchTree<T>::operator>(const T &item1, const T &item2)
{
	bool entry = false;
	if (item1 > item2)
		entry = true;
	
	return entry;
}
template<class T>
ostream & operator<<(ostream & out, const BinarySearchTree<T>& bst)
{
	bst.Print(out, bst.root);
	return out;
}

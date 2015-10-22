#include<iostream>
#include<string>
#include"RedBlackTree.h"

using namespace std;

template<class T>
RedBlackTree<T>::RedBlackTree(void) {
	leaf = new RbNode<T>;
	leaf->left = leaf->right = NULL;
	leaf->color = RbNode<T>::BLACK;

	m_root = new RbNode<T>();
	m_root->left = m_root->right = NULL;
}
template<class T>
RedBlackTree<T>::~RedBlackTree() {

}
template<class T>
void RedBlackTree<T>::Insert(T& item) {

}
template<class T>
void RedBlackTree<T>::Print(void) const {

}
template<class T>
void RedBlackTree<T>::changeColor(RbNode<T>*& node, RbNode<T>*& parent, RbNode<T>*& grant) {
	if (node->color == RbNode<T>::BLACK)
		node->color == RbNode<T>::RED;
	else if (node->color == RbNode<T>::RED)
		node->color == RbNode<T>::BLACK;
	if (parent->color == RbNode<T>::BLACK)
		parent->color == RbNode<T>::RED;
	else if (parent->color == RbNode<T>::RED)
		parent->color == RbNode<T>::BLACK;
	if (grant->color == RbNode<T>::BLACK)
		grant->color == RbNode<T>::RED;
	else if (grant->color == RbNode<T>::RED)
		grant->color == RbNode<T>::BLACK;
}
template<class T>
void RedBlackTree<T>::RotateLeft(RbNode<T>*& node, RbNode<T>*& Pnode) {

}
template<class T>
void RedBlackTree<T>::RotateRight(RbNode<T>*& node, RbNode<T>*& Pnode) {

}
template<class T>
void RedBlackTree<T>::Print(void RotateLeft(RbNode<T>*& node, int n) {

}
template<class T>
void RedBlackTree<T>::Delete(RbNode<T>* node) const {

}
template<class T>
void RedBlackTree<T>::section(RbNode<T>* node, RbNode<T>* parent,
	RbNode<T>* grand, RbNode<T>* great) {

}
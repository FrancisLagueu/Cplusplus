#include<iostream>
#include<string>
#include"BinarySearchTree.h"

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H


using namespace std;

template<class T>
struct RbNode : Node {
	enum Color{RED, BLACK};
	Color color;
	RbNode(const T&item, Color col=BLACK ): data(item), left(NULL), right(NULL), color(col){}
	friend class RedBlackTree<T>;
};
template<class T>
class RedBlackTree {
public:
	RedBlackTree(void);
	~RedBlackTree();
	void Insert(T& item);
	void Print(void) const;
private:
	void changeColor(RbNode<T>*& node, RbNode<T>*& parent, RbNode<T>*& grant)
	void RotateLeft(RbNode<T>*& node, RbNode<T>*& Pnode);
	void RotateRight(RbNode<T>*& node, RbNode<T>*& Pnode);
	void Print(void RotateLeft(RbNode<T>*& node, int n);
	void Delete(RbNode<T>* node) const;
	void section(RbNode<T>* node, RbNode<T>* parent,
		RbNode<T>* grand, RbNode<T>* great);
	RbNode<T>* m_root;
	RbNode<T>*& leaf;

};
#endif 

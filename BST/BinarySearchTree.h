
#include<iostream>
#include<string>

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


using namespace std;
template<class T>
struct Node {
	T data;
	Node* left;
	Node* right;
	Node(const T& item):data(item), left(NULL), right(NULL){}
};

template<class T>
class BinarySearchTree {
private:
	Node<T>* root;
	void Insert(Node*& node, const T& item);
	void DeleteTree(Node*);
	void Delete(Node*&, T&);
	void Print(ostream&, Node*) const;
	Node find(T);
	friend ostream& operator<<(ostream&, const BinarySearchTree<T>&);
	bool operator < (const T&, const T&);
	bool operator > (const T&, const T&);
public:
	BinarySearchTree<T>():root(NULL){}
	~BinarySearchTree<T>();
	void Insert(const T&);
	Node findMin();
	Node findMax();
	Node find(Node* , T);
	void Delete(T&);

};
#endif 



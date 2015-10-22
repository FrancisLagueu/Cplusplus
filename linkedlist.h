#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<string>
using namespace std;

struct Node {
	auto data;
	Node* next;
	Node(const auto& d);
};

class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList&);
	~LinkedList();

	LinkedList& operator = (const LinkedList&);

	bool isEmpty() const;
	int size() const;
	bool Insert(const auto& dat);
	bool Delete(const auto& dat);
	bool Find(const auto& dat);

	friend ostream& operator << (ostream&, const LinkedList&);

private:
	void Clear();
	void Copy(const LinkedList&);
	Node* head;
	int num;

};


#endif LINKEDLIST_H
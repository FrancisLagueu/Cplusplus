#include<iostream>
#include<string>
#include"linkedlist.h"

using namespace std;

Node::Node(const auto& d) {
	data = d;
	next = NULL;
}
LinkedList::LinkedList() {
	head = NULL;
	num = 0;
}
LinkedList::LinkedList(const LinkedList& lt) {
	head = NULL;
	num = 0;
	Copy(lt);
}
LinkedList::~LinkedList() {
	Clear();
}
LinkedList& LinkedList:: operator = (const LinkedList& lt) {
	if (this != &lt) {
		Clear();
		Copy(lt);
	}
	return *this;
}

bool LinkedList::isEmpty() const {
	if (head == NULL)
		return true;
	else
		return false;
}
int LinkedList::size() const {
	int num = 0;
	Node* P = head;
	while (P != NULL) {
		P = P->next;
		num++;
	}
	return num;
}
bool LinkedList::Insert(const auto& dat) {
	bool entry;
	Node* P = new Node(dat);
	if (head == NULL) {
		head = new Node(dat);
		num = 1;
		entry = true;
	}
	else if (dat < head->data) {
		P->next = head;
		head = P;
		num++;
		entry true;
	}
	else if (dat == head->data) {
		return false;
	}
	else {
		Node* P = head;
		Node* Q = head->next;
		while (Q != NULL && dat > Q->data) {
			P = Q;
			Q = Q->next;
		}
		if ((Q == NULL) || (dat < Q->data)) {
			Node* R = new Node(dat);
			P->next = R;
			R->next = Q;
			num++;
			entry true;
		}
		else if(Q != NULL) {
			if(dat == Q->data)
				entry = false;
			else {
				Node* R = new Node(dat);
				P->next = R;
				R->next = Q;
				num++;
				entry = true;
			}
		}
	}
	return entry;
}
bool LinkedList::Delete(const auto& dat) {
	bool entry = true;
	if (head == NULL)
		entry = false;
	else if (dat == head->data) {
		Node* P = head;
		head = head->next;
		delete P;
	}
	else {
		Node* P = head;
		Node* Q = head->next;
		while (Q != NULL && !(dat == Q->data)) {
			P = Q;
			Q = Q->next;
		}
		if (Q != NULL && dat == Q->data) {
			P->next = Q->next;
			delete Q;
		}
		else {
			entry = false;
		}
	}
	num--;
	return entry;
}
bool LinkedList::Find(const auto& dat) {
	Node* P = head;
	bool entry = true;
	if (head == NULL) {
		entry = false;
	}
	else if (dat == P->data) {
		dat = P->data;
		P = P->next;
	}
	else {
		Node* P = head;
		Node* Q = head->next;
		while (Q != NULL && !(dat == Q->data)) {
			P = Q;
			Q = Q->next;
		}
		if (Q != NULL && dat == Q->data) {
			dat = Q->data;
			Q = Q->next;
		}
		else
			entry = false;
	}
	return entry;
}
ostream& operator <<(ostream& os, const LinkedList& lt) {
	Node* P = lt.head;
	while (P != NULL) {
		os << P->data << endl;
		P = P->next;
	}
	return os;
}

void LinkedList::Clear() {
	Node* P;
	while (head!=NULL)
	{
		P = head;
		head = head->next;
		delete P;
	}
	num = 0;
}

void LinkedList::Copy(const LinkedList& lt) {
	num = lt.num;
	if (lt.isEmpty()) {
		head = NULL;
	}
	else {
		head = new Node(lt.head->data);
		Node* Q = head;
		Node* P = lt.head->next;
		while (P != NULL) {
			Q->next = new Node(P->data);
			P = P->next;
			Q = Q->next;
		}
	}
}
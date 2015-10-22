#include <iostream>
#include <string>
#include "linkedlist.h"
using namespace std;


void AddEntry(LinkedList&);
void DeleteEntry(LinkedList&);
void LookupEntry(const LinkedList&);
void Help();

int main() {
	LinkedList list;
	char choice;
	Help();
	do {
		cout << "Enter command: ";
		cin >> choice;
		switch (choice) {
		case 'a':
		case 'A':
			AddEntry(list);
			break;
		case 'd':
		case 'D':
			DeleteEntry(list);
			break;
		case 'h':
		case 'H':
			Help();
			break;
		case 'l':
		case 'L':
			LookupEntry(list);
			break;
		case 'p':
		case 'P':
			cout << "\n" << list;
			break;
		case 'q':
		case 'Q':
			cout << "\nExiting command block.\n";
			break;
		case 'n':
		case 'N':
			cout << "\nNumber of item in the list: "
				<< list.Size() << endl;
			break;
		default:
			cout << "Invalid command.\n";
			break;
		}
		cout << "\n";
	} while (choice != 'q' && choice != 'Q');

	//  The next block tests the destructor
	{
		LinkedList copy1 = list;  // tests copy constructor
		cout << "The copy constructor produces a list with "
			<< copy1.Size() << " elements:\n";
		cout << copy1;

		LinkedList copy2;
		copy2 = list;    // tests assignment operator
		cout << "\nThe assignment operator produces a list with "
			<< copy2.Size() << " elements:\n";
		cout << copy2;

		copy2 = list;    // tests assignment operator again
		cout << "\nThe assignment operator produces a list with "
			<< copy2.Size() << " elements:\n";
		cout << copy2;
	}
	cout << "\nThe destructor call was apparently successful.\n";
	cin.get();
	cin.get();
	return 0;
}

void AddEntry(LinkedList& pb) {
	auto last;
	cout << "Enter an item: ";
	cin >> last;
	bool success = pb.Insert(last);
	if (success) {
		cout << "\nAdded to the list item.\n";
	}
	else {
		cout << "\nError: a person with this name is already in the list.\n";
	}
}

void DeleteEntry(LinkedList& pb) {
	auto last;
	cout << "Enter an item: ";
	cin >> last;
	bool success = pb.Delete(last);
	if (success) {
		cout << "\nDeleted from the list.\n";
	}
	else {
		cout << "\nError: the item doesn't exist in the list.\n";
	}
}

void LookupEntry(const LinkedList& pb) {
	auto last;
	cout << "Enter an item: ";
	cin >> last;
	bool success = pb.Find(last);
	if (success) {
		cout << "\nThe item is " << last << ". \n";
	}
	else {
		cout << "\nError: no one by this name is in the phone book.\n";
	}
}

void Help() {
	cout << "The following commands are available: \n"
		<< "   a : Add an item in the list. \n"
		<< "   d : Delete an item from the list. \n"
		<< "   h : Help -- print this list of commands. \n"
		<< "   l : Look up an item in the list. \n"
		<< "   n : Report the number item in the list. \n"
		<< "   p : Print the entire list. \n"
		<< "   q : Quit. \n";
}

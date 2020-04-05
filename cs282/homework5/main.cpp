#include "ModernLinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	ModernLinkedList testList;

	cout << "Instantiate an empty linked list: " << endl;
	testList.PrintList();
	cout << "" << endl;


	cout << "Add intergers using PushFront(): " << endl;
	cout << "List before add: ";
	testList.PrintList();

	testList.PushFront(2);
	testList.PrintList();
	testList.PushFront(3);
	testList.PrintList();
	testList.PushFront(4);
	testList.PrintList();
	testList.PushFront(5);
	testList.PrintList();
	cout << "" << endl;

	cout << "Add intergers using PushBack(): " << endl;
	cout << "List before add: ";
	testList.PrintList();

	testList.PushBack(6);
	testList.PrintList();
	testList.PushBack(7);
	testList.PrintList();
	testList.PushBack(8);
	testList.PrintList();
	cout << "" << endl;

	cout << "Inserting 32 at index 2 using Insert(): " << endl;
	cout << "List before insertion: ";
	testList.PrintList();

	testList.Insert(2, 32);
	testList.PrintList();
	cout << "" << endl;

	cout << "Accessing data in a Node using [] operator: " << endl;
	cout << "List: ";
	testList.PrintList();

	cout << "Indexing item at index 4 in the list: "<< testList[4] << endl;
	cout << "" << endl;

	cout << "Using PopFront() to remove Node at the front: " << endl;
	cout << "List before removing: ";
	testList.PrintList();

	testList.PopFront();
	testList.PrintList();
	testList.PopFront();
	testList.PrintList();
	cout << "" << endl;

	cout << "Using PopBack() to remove Node at the back: " << endl;
	cout << "List before removing: ";
	testList.PrintList();

	testList.PopBack();
	testList.PrintList();
	testList.PopBack();
	testList.PrintList();
	cout << "" << endl;

	cout << "Clearing the list using Clear(): " << endl;
	cout << "List before clearing: ";
	testList.PrintList();

	testList.Clear();
	testList.PrintList();
	cout << "" << endl;
}
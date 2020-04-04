#include "ModernLinkedList.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	ModernLinkedList testList;

	cout << "List before adding: " << endl;
	testList.PrintList();
	testList.PushFront(2);
	testList.PushFront(3);
	testList.PushFront(4);
	testList.PrintList();
	testList.PushFront(5);
	cout << "List after adding: " << endl;
	testList.PrintList();

	cout << "testing pushBack: " << endl;
	testList.PushBack(8);
	testList.PrintList();

	cout << "Size of list: " << testList.Size() << endl;

	cout << "Testing insert: " << endl;
	testList.Insert(2, 11);
	testList.PrintList();

	cout << "Size of list: " << testList.Size() << endl;

	//cout << "Removing" << endl;
	//testList.PopBack();
	//testList.PrintList();

	//cout << "Size of list: " << testList.Size() << endl;

	cout << "Testing remove at index: " << endl;
	testList.RemoveAt(2);
	testList.PrintList();
	cout << "Size of list: " << testList.Size() << endl;

	cout << "Testing popFront: " << endl;
	testList.PopFront();
	testList.PrintList();
	//testList.PopFront();
	//testList.PrintList();
	//testList.PopFront();
	//testList.PrintList();
	//testList.PopFront();
	//testList.PrintList();
	//testList.PopFront();
	//testList.PrintList();
	cout << "Size of list: " << testList.Size() << endl;

	cout << "Testing [] operator: " << testList[3] <<endl; 

	cout << "Testing clear: " << endl;
	testList.Clear();
	testList.PrintList();
	cout << "Size of list: " << testList.Size() << endl;

}
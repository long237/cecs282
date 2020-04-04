#include "ModernLinkedList.h"
#include <memory>
#include <iostream>
using namespace std;

void ModernLinkedList::PushFront(int value) {
	auto newNode = std::make_unique<Node>(value);
	// Any time we change a link, we must use std::move.
	newNode->mNext = std::move(mHead);

	// Transfer ownership of this new head node to the List object.
	mHead = std::move(newNode);

	// Increase the size by 1.
	mSize++;
}

void ModernLinkedList::PrintList() const {
	// To walk this list, we need to create a temp that points to the head node, and then gets moved
	// to the next, to the next, etc. This temp does not want to claim ownership of any of these nodes,
	// so it can't be a unique_ptr. A "raw" Node pointer will let us "use" each Node's values without
	// having to be an owner of that memory.

	cout << "[";
	Node* temp = mHead.get(); // reminder: a unique_ptr's .get() gives us back the raw pointer.
	// As long as the Node that temp points to is not null.
	while (temp != nullptr) {
		if (temp != mHead.get()) {
			// Separate each element with a comma.
			cout << ", ";
		}
		cout << temp->mData;
		temp = temp->mNext.get();
	}
	cout << "]" << endl;
}

void ModernLinkedList::PopBack() {
	if (mSize == 1) {
		// Set head to nullptr, which destroys the only remaining node.
		// Reminder: to change ownership, use std::move.
		mHead = std::move(nullptr);
		mSize = 0;
	}
	else {
		// First walk to the second-to-last node in the list.
		// See PrintList().
		Node* temp = mHead.get();
		while (temp->mNext->mNext != nullptr) {
			temp = temp->mNext.get();
		}

		// If temp's next's next is null, then temp is the second to last node.
		// temp's next must now be set to null, which will destroy what used to be last.
		temp->mNext = std::move(nullptr);
		mSize--;
	}
}

void ModernLinkedList::PushBack(int value) {
	//create a temporarily variables to point to Nodes in the list
	//Get the last node in the list with the loop
	Node* temp = mHead.get();
	//As long as temp is not null keep going
	while (temp->mNext != nullptr) {
		temp = temp->mNext.get();
	}

	//make a new node with the data provided from the parameter
	unique_ptr<Node> newNode = make_unique<Node>(value);
	
	//set new node mNext point to nullptr
	newNode->mNext = std::move(nullptr);
	//transfer ownership of "newNode" to temp->mNext
	temp->mNext = std::move(newNode);
	mSize++;	
}

void ModernLinkedList::Insert(int index, int value) {
	Node* temp = mHead.get();
	unique_ptr<Node> newNode = make_unique<Node>(value);

	//find the Node before the insert position
	for (int i = 0; i < (index - 1); i++) {
		temp = temp->mNext.get();
	}
	
	//transfer ownership of the temp->mNext to newNode
	newNode->mNext = std::move(temp->mNext);
	//transfwer ownership of the newNode to temp->mNext
	temp->mNext = std::move(newNode);
	mSize++;
}

void ModernLinkedList::PopFront() {
	if (mSize == 1) {
		//set head to nullptr if there is only one Node in the list
		mHead = std::move(nullptr);
		mSize = 0;
	}
	else {
		//set head to the Node that the first Node point to
		mHead = std::move(mHead->mNext);
		mSize--;
	}
}

void ModernLinkedList::RemoveAt(int index) {
	Node* temp = mHead.get();
	//find the node before the Node to be removed
	for (int i = 0; i < (index - 1); i++) {
		temp = temp->mNext.get();
	}

	//transfer ownership of the Node after the Node to be removed to the temp Node
	//In other word, make the temp Node point to the Node that after the Node to be removed
	temp->mNext = std::move(temp->mNext->mNext);
	mSize--;
}

void ModernLinkedList::Clear() {
	//set the head to nullptr to destroy all following Nodes
	mHead = std::move(nullptr);
	mSize = 0;
}

int& ModernLinkedList::operator[](int index) {
	Node* temp = mHead.get();

	for (int i = 0; i < index; i++) {
		temp = temp->mNext.get();
	}
	return temp->mData;
}

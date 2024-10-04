#pragma once
#include <stdexcept>
using namespace std;



class SingleLinkedList
{
private: 
	struct Node {
		int data;
		Node* next;

		Node(const int& data_item = 0, Node* next_ptr = nullptr) : data(data_item), next(next_ptr) {}
	};

public: 
	SingleLinkedList() : head(nullptr), tail(nullptr), numItems(0) {}
	Node* head;
	Node* tail;
	int numItems;

	//push_front is intended to add a new Node to the top of the single linked list using the data object "value"
	void push_front(int value);


	//push_back adds a new node at the back of the list using the data object "value"
	void push_back(int value);

	//pop_front removes the first item from the list
	void pop_front();

	//pop_back removes the last node from the list
	void pop_back();

	//front function returns the data stored at the first node in the list
	int front();

	//back function returns the data stored at the last node in the list
	int back();

	//empty function returns a boolean value that tells whether the list is empty
	bool empty();

	//Insert function will insert a node with the given value at the specified index
	void Insert(size_t index, int item);

	//remove will remove a node at a givn index
	void remove(size_t index) {
		if (index >= numItems) {
			throw std::runtime_error("Provided index is out of range");
			}
		else {
			if (index == 0) {
				pop_front();
				}
			else {
				Node* temp = head;
				for (size_t i = 0; i < index - 1; i++) {
					temp = temp->next;
				}
				Node* node_to_remove = temp->next;
				temp->next = node_to_remove->next;
				if (node_to_remove == tail) {
					tail = temp;
				}
				delete node_to_remove;
				numItems--;
			}
		}
	}

	//finds and returns the index for the given item;
	size_t find(int item) {
		size_t index = 0;
		Node* temp = head;
		while (temp != nullptr) {
			if (temp->data == item) {
				return index;
			}
			index++;
			temp = temp->next;
		}
		return index;
	}
};






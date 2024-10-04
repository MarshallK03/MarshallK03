#include "SingleLinkedList.h"
using namespace std;

void SingleLinkedList::push_front(int value) {
	Node* new_node = new Node();
	new_node->data = value;
	new_node->next = head;
	head = new_node;
	if (tail == nullptr) {
		tail = new_node;
	}
	numItems++;
}

void SingleLinkedList::push_back(int value) {
	Node* new_node = new Node();
	new_node->data = value;
	new_node->next = nullptr;
	if (tail != nullptr) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = new_node;
		tail = new_node;
	}
	numItems++;
}

void SingleLinkedList::pop_front() {
	if (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
		if (head == nullptr) {
			tail = nullptr;
		}
		numItems--;
	}
}

void SingleLinkedList::pop_back() {
	if (tail != nullptr) {
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* temp = head;
			while (temp->next != tail) {
				temp = temp->next;
			}
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}
		numItems--;
	}
}

int SingleLinkedList::front() {
	if (head != nullptr) {
		return head->data;
	}
	else {
		throw std::runtime_error("List is empty");
	}
}

int SingleLinkedList::back() {
	if (tail != nullptr) {
		return tail->data;
	}
	else {
		throw std::runtime_error("list is empty");
	}
}

bool SingleLinkedList::empty() {
	return (numItems == 0);
}

void SingleLinkedList::Insert(size_t index, int item) {
	if (index > numItems) {
		push_back(item);
	}
	else {
		Node* new_node = new Node();
		new_node->data = item;
		if (index == 0) {
			new_node->data = item;
			head = new_node;
			if (tail == nullptr) {
				tail = new_node;
			}
		}
		else {
			Node* temp = head;
			for (size_t i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node;
			if (new_node->next = nullptr) {
				tail = new_node;
			}
		}
		numItems++;
	}
}



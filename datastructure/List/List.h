#pragma once

#include <iostream>
using namespace std;

template<typename T>
class List {
public:
	explicit List() {
		head = new Node();
		head->data = T();
		head->next = nullptr;

		tail = new Node();
		tail->data = T();
		tail->next = nullptr;
	}
	~List() {
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	struct Node {
		T data;
		Node* next;
	};
public:
	void Insert(const T& item) {
		Node* newNode = new Node();
		newNode->data = item;

		if (!head->next) head->next = newNode;
		else tail->next = newNode;

		tail = newNode;
	}

	void Print() {
		if (!head->next) {
			cout << "empty" << endl;
			return;
		}

		Node* cur = head->next;

		while (cur) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
private:
	Node* head = nullptr;
	Node* tail = nullptr;
};

// Shivam Kumar 555585 BSCS-15-D

#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};


class DoublyList {
private:
	node* head;
	node* tail;
public:
	DoublyList() {
		head = nullptr;
		tail = nullptr;
	}
	void AddNode(int value);
	void PrintForward();
	void PrintBackward();
	void ClearList();
};

void DoublyList::AddNode(int value) {
	node* newNode = new node;
	newNode->data = value;
	newNode->prev = tail; //append after the tail
	newNode->next = nullptr; //since it is appended, so it is at the end, no next

	if (head == nullptr) {
		//if empty list then start with new Node
		head = newNode;
	}
	else {
		tail->next = newNode; // else point tail to new node
	}
	tail = newNode; //make new node the tail
}

void DoublyList::PrintForward() {
	node* curr = head; //traversal pointer
	cout << "Print Forward: " << endl;
	cout << "NULL <-> "; //since it is doubly
	while (curr != nullptr) {
		cout << curr->data << "<->";
		curr = curr->next; //traverse ahead
	}
	cout << "NULL" << endl; //edn at null
}

void DoublyList::PrintBackward() {
	node* curr = tail; //traversal pointer starts at tail
	cout << "Print Backward: " << endl;
	cout << "NULL <-> "; //since it is doubly
	while (curr != nullptr) {
		cout << curr->data << " <-> ";
		curr = curr->prev; //traverse behind
	}
	cout << "NULL" << endl; //edn at null
}

void DoublyList::ClearList() {
	node* curr = head;
	cout << "Clearing List.." << endl;
	while (curr != nullptr) {
		node* temp = curr;
		curr = curr->next; //traverse next
		delete temp;
	}
	head = nullptr;
	tail = nullptr; // make pointers point to empty lsit
}

int main() {
	DoublyList list;
	int count, value;

	cout << "Enter number of integers (non-negative): ";
	cin >> count;

	for (int i = 0; i < count; i++) {
		cout << "Enter integer " << i + 1 << ": ";
		cin >> value;
		list.AddNode(value);
	}

	if (count == 0) {
		cout << "List is empty!" << endl;
	}

	list.PrintForward();
	list.PrintBackward();

	list.ClearList();

	return 0;
}

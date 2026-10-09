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
	void InsertBefore(int position, int value);
	void DeleteNode(int value);
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

void DoublyList::InsertBefore(int position, int value) {
	if (position < 1) {
		cout << "Not a valid position" << endl;
		return;
	}

	node* curr = head;
	node* newNode = new node;
	newNode->data = value;

	int count = 1;

	//check if list is empty
	if (head == nullptr) {
		delete newNode;
		cout << "List is empty" << endl;
		return;
	}

	//traverse to the required position
	while (curr != nullptr && count < position) {
		curr = curr->next;
		count++;
	}

	//check if position exists
	if (curr == nullptr) {
		delete newNode;
		cout << "Not a valid position" << endl;
		return;
	}

	newNode->next = curr; //point new node to current node
	newNode->prev = curr->prev; //point new node to previous node

	if (curr->prev == nullptr) {
		head = newNode; //if inserting before head, make new node the head
	}
	else {
		curr->prev->next = newNode; //point previous node to new node
	}

	curr->prev = newNode; //point current node back to new node
}

void DoublyList::DeleteNode(int value) {
	node* curr = head; //traversal pointer

	//check if list is empty
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return;
	}

	//traverse to find the required value
	while (curr != nullptr && curr->data != value) {
		curr = curr->next;
	}

	//check if value exists
	if (curr == nullptr) {
		cout << "Value not found" << endl;
		return;
	}

	//if deleting the head node
	if (curr == head) {
		head = curr->next;
	}
	else {
		curr->prev->next = curr->next; //connect previous node to next node
	}

	//if deleting the tail node
	if (curr == tail) {
		tail = curr->prev;
	}
	else {
		curr->next->prev = curr->prev; //connect next node to previous node
	}

	delete curr; //delete the required node
	cout << "Node deleted successfully" << endl;
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

	list.InsertBefore(2, 15);
	list.PrintForward();

	list.DeleteNode(20);
	list.PrintForward();

	list.PrintForward();
	list.PrintBackward();

	list.ClearList();

	return 0;
}

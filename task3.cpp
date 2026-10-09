// Shivam Kumar 555585 BSCS-15-D

#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class CircularList {
private:
	node* head;
	node* tail;
public:
	CircularList() {
		head = nullptr;
		tail = nullptr;
	}
	void AddNode(int value);
	void PrintList();
	void CountNodes();
	void ClearList();
};

void CircularList::AddNode(int value) {
	node* newNode = new node;
	newNode->data = value;

	if (head == nullptr) {
		head = newNode;
	}
	else {
		tail->next = newNode;
	}
	tail = newNode;
	tail->next = head;
}

void CircularList::PrintList() {
	node* curr = head; //traversal
	if (head == nullptr) cout << "Empty List" << endl;
	else {
		cout << "Head -> "; //start from head
		do {
			cout << curr->data << " -> ";
			curr = curr->next; //forward traverse
		} while (curr != head);
		cout << "Tail" << endl; // end at tail
	}
}

void CircularList::CountNodes() {
	node* curr = head; //traversal
	int count = 0;

	if (head == nullptr) cout << "Empty List" << endl;
	else {
		do {
			curr = curr->next; //forward traverse
			count++;
		} while (curr != head);
		cout << "List size: " << count << endl;
	}
}

void CircularList::ClearList() {
	if (head == nullptr) {
		return;
	}

	cout << "Clearing List..." << endl;

	// Break the loop so we can safely delete linearly
	tail->next = nullptr;

	node* curr = head;
	while (curr != nullptr) {
		node* temp = curr;
		curr = curr->next;
		delete temp;
	}

	head = nullptr;
	tail = nullptr;
	cout << "List cleared successfully." << endl;
}

int main() {
	CircularList list;

	// test 1: empty list
	cout << "Test 1: Empty List" << endl;
	list.PrintList();
	list.CountNodes();

	// test 2: one node
	cout << "Test 2: One Node" << endl;
	list.AddNode(5);
	list.PrintList();
	list.CountNodes();
	list.ClearList();

	// test 3: three nodes (10, 20, 30)
	cout << "Test 3: Three Nodes" << endl;
	list.AddNode(10);
	list.AddNode(20);
	list.AddNode(30);
	list.PrintList();
	list.CountNodes();

	// cleanup
	list.ClearList();

	return 0;
}

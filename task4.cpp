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
	void DeleteNode(int value);

};

void CircularList::DeleteNode(int value) {
	if (head == nullptr) { //if empty end function
		cout << "Empty List" << endl;
		return;
	}

	node* curr = head; //start from head
	node* prev = nullptr; //prev node pointer
	bool found = false;

	do {
		if (curr->data == value) {
			found = true;
			break;
		}
		prev = curr;
		curr = curr->next; //forward traverse
	} while (curr != head);

	if (!found) {
		cout << "Value " << value << " not found in list." << endl;
		return;
	}

	if (head == tail) {
		delete curr;
		head = nullptr;
		tail = nullptr; //make pointers point to empty list
		return;
	}

	if (curr == head) {
		head = head->next; //move head forward
		tail->next = head; //preserve circular link
	}
	else if (curr == tail) {
		tail = prev; //move tail backward
		tail->next = head; //preserve circular link
	}
	else {
		prev->next = curr->next; //bypass current node
	}

	delete curr;
}

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
	list.DeleteNode(10);

	// test 2: add 10, 20, 30
	cout << "\nTest 2: Add 10, 20, 30" << endl;
	list.AddNode(10);
	list.AddNode(20);
	list.AddNode(30);
	list.PrintList();
	list.CountNodes();

	// test 3: missing value
	cout << "Test 3: Missing value" << endl;
	list.DeleteNode(40);

	// test 4: delete head (10)
	cout << "Test 4: Delete head (10)" << endl;
	list.DeleteNode(10);
	list.PrintList();
	list.CountNodes();

	// test 5: delete tail (30)
	cout << "Test 5: Delete tail (30)" << endl;
	list.DeleteNode(30);
	list.PrintList();
	list.CountNodes();

	// test 6: delete only node (20)
	cout << "Test 6: Delete only node (20)" << endl;
	list.DeleteNode(20);
	list.PrintList();
	list.CountNodes();

	// test 7: duplicates
	cout << "Test 7: Duplicates" << endl;
	list.AddNode(10);
	list.AddNode(20);
	list.AddNode(20);
	list.AddNode(30);
	list.PrintList();

	list.DeleteNode(20);
	list.PrintList();
	list.CountNodes();

	list.ClearList();

	return 0;
}

// Shivam Kumar 555585 BSCS-15-D

#include <iostream>
using namespace std;

// node structure for the linked stack
struct Node {
	int data;
	Node* next;
};

class LinkedStack {
private:
	Node* top; // points to the top node of the stack
public:
	// initialize empty stack
	LinkedStack() {
		top = nullptr;
	}


	void Push(int value);
	void Pop();
	void Peek();
	bool IsEmpty();
	void Display();
	void ClearStack();
};

void LinkedStack::Push(int value) {
	// allocate memory for new node
	Node* newNode = new Node;
	newNode->data = value;

	// point new node to current top then update top
	newNode->next = top;
	top = newNode;
}

void LinkedStack::Pop() {
	// check underflow
	if (IsEmpty()) {
		cout << "Stack is empty. Cannot pop." << endl;
		return;
	}

	// keep track of node to delete
	Node* temp = top;
	cout << "Popped value: " << temp->data << endl;

	// move top to next node and free memory
	top = top->next;
	delete temp;
}

void LinkedStack::Peek() {
	// check underflow
	if (IsEmpty()) {
		cout << "Stack is empty. Nothing to peek." << endl;
		return;
	}

	// show top value without removing it
	cout << "Top value: " << top->data << endl;
}

bool LinkedStack::IsEmpty() {
	// stack is empty when top pointer has null
	return (top == nullptr);
}

void LinkedStack::Display() {
	// check if there is anything to print
	if (IsEmpty()) {
		cout << "Stack is empty." << endl;
		return;
	}

	// start from top and traverse to bottom
	Node* curr = top;
	cout << "Stack elements (top to bottom):" << endl;
	while (curr != nullptr) {
		cout << curr->data;
		if (curr == top) {
			cout << " (Top)";
		}
		cout << endl;
		curr = curr->next;
	}
}

void LinkedStack::ClearStack() {
	// delete nodes one by one until top becomes null
	while (top != nullptr) {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}

int main() {
	LinkedStack stack;
	int choice;
	int val;

	// menu loop
	do {
		cout << endl;
		cout << "Menu" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Display" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Enter integer to push: ";
			cin >> val;
			stack.Push(val);
		}
		else if (choice == 2) {
			stack.Pop();
		}
		else if (choice == 3) {
			stack.Peek();
		}
		else if (choice == 4) {
			stack.Display();
		}
		else if (choice == 5) {
			cout << "Exiting program. Clearing remaining memory..." << endl;
			stack.ClearStack();
		}
		else {
			cout << "Invalid choice. Please choose between 1 and 5." << endl;
		}

	} while (choice != 5);

	return 0;
}

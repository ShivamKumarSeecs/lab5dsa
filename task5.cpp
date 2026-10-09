// Shivam Kumar 555585 BSCS-15-D

#include <iostream>
using namespace std;

class ArrayStack {
private:
	int items[5]; // array to store stack elements
	int top; // index of top element
public:
	// set top to -1 because stack is empty at start
	ArrayStack() {
		top = -1;
	}
	void Push(int value);
	void Pop();
	void Peek();
	bool isEmpty();
	bool isFull();
	void Display();
};

void ArrayStack::Push(int value) {
	// check if stack has reached max size
	if (isFull()) {
		cout << "Stack Full" << endl;
		return;
	}
	// move top up by one and insert value
	items[++top] = value;
}

void ArrayStack::Pop() {
	// check if there is anything to remove
	if (isEmpty()) {
		cout << "Empty Stack" << endl;
		return;
	}
	// print top value then decrease top index
	cout << "Popped: " << items[top--] << endl;
}

void ArrayStack::Peek() {
	// check if stack is empty before reading top
	if (isEmpty()) {
		cout << "Empty Stack" << endl;
		return;
	}
	// just look at the top element without removing it
	cout << "Stack Top: " << items[top] << endl;
}

bool ArrayStack::isFull() {
	// full when top reaches the last array index which is 4
	return (top + 1 == 5);
}

bool ArrayStack::isEmpty() {
	// empty when top is still at initial position -1
	return (top == -1);
}

void ArrayStack::Display() {
	// cannot print if there are no elements
	if (isEmpty()) {
		cout << "Empty Stack" << endl;
		return;
	}

	// start from top and go down to index 0
	for (int i = top; i >= 0; i--) {
		cout << items[i];
		// mark the top element
		if (i == top) {
			cout << " (Top)";
		}
		cout << endl;
	}
}

int main() {
	ArrayStack s;

	// push 10 to 50
	cout << "Pushing 10, 20, 30, 40, 50:" << endl;
	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.Push(40);
	s.Push(50);
	s.Display();

	// push sixth value to show overflow
	cout << endl;
	cout << "Pushing 60:" << endl;
	s.Push(60);

	// remove 50 and check top
	cout << endl;
	cout << "Popping top element:" << endl;
	s.Pop();

	cout << endl;
	cout << "Peeking top element:" << endl;
	s.Peek();

	// clear out the remaining nodes
	cout << endl;
	cout << "Emptying stack:" << endl;
	s.Pop();
	s.Pop();
	s.Pop();
	s.Pop();

	// test pop on empty stack to show underflow
	cout << endl;
	cout << "Popping from empty stack:" << endl;
	s.Pop();

	// test peek on empty stack
	cout << endl;
	cout << "Peeking empty stack:" << endl;
	s.Peek();

	return 0;
}

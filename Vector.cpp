#include "Vector.h"
#include <stack>
using namespace std;

int Vector::Stack() {
	return 0;
}

bool Vector::isEmpty() {
	return stack.empty();
}

void Vector::push(int value) {
	stack.push_back(value);
}

int Vector::pop() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty");
	}
	int top = stack.back();
	stack.pop_back();
	return top;
}

int Vector::top() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty");
	}
	return stack.back();
}

double Vector::average() {
	if (isEmpty()) {
		throw runtime_error("Stack is empty");
	}
	double sum = 0.0;
	for (int val : stack) {
		sum += val;
	}

	return sum / stack.size();
}

void Vector::printStack() {
	for (int val : stack) {
		cout << val << endl;
	}
	cout << endl;
}

int main() {
	//create instace of the Vector Stack
	Vector stack;

	//check if the stack is empty
	cout << "Is the stack empty? : " << (stack.isEmpty() ? "Yes" : "No") << endl;

	//insert values onto the stack
	cout << "Inserting values into stack" << endl;
	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.push(40);
	stack.push(50);

	//print out the stack
	cout << "Elements of the stack: " << endl;
	stack.printStack();

	//remove an element of the stack
	int popVal = stack.pop();
	cout << "Removed value: " << popVal << endl;

	//print the elements of the vector after pop
	cout << "Stack elements after pop: " << endl;
	stack.printStack();

	//find top value of the stack
	int topVal = stack.top();
	cout << "Top Value: " << topVal << endl;

	//find the average of the stack elements
	cout << "Average of the elements in the stack: " << stack.average() << endl;
}
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
 
using namespace std;

class Vector
{
private:
	std::vector<int> stack;

public:
	//default constructor to make a stack object
	int Stack();

	//check if the stack is empty
	bool isEmpty();
	
	//push an element onto the stack
	void push(int value);

	//pop an element off the top of the stack
	int pop();

	//find the top element of the stack
	int top();

	//find the average value of the stack of elements
	double average();

	//print the stack's elements
	void printStack();
};


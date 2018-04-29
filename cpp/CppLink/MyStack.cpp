/*
 * Stack.cpp
 *
 *  Created on: 2018年4月27日
 *      Author: anker
 */

#include <iostream>
#include <cstddef>

#include "MyStack.h"
using namespace std;
namespace stacksavitch {

MyStack::MyStack() {
	top = NULL;
}

MyStack::~MyStack() {
	char next;
	while (!empty()) {
		next = pop();
	}
}
//拷贝构造函数
MyStack::MyStack(const MyStack& a_stack) {
	if (a_stack.top != NULL) {
		top = new StackFrame();
		top->data = a_stack.top->data;
		top->link = a_stack.top->link;
	}

}
void MyStack::push(char the_symbol) {
	StackFrame* tem_ptr;
	tem_ptr = new StackFrame();
	tem_ptr->data = the_symbol;
	if (top == NULL) {
		top = tem_ptr;
	} else {
		tem_ptr->link = top;
		top = tem_ptr;
	}

}
char MyStack::pop() {
	if (empty()) {
		cout << "Error:popping an empty stack.\n" << endl;
		exit(1);
	}
	char result = top->data;
	StackFrame* temp_ptr;
	temp_ptr = top;
	top = top->link;
	delete temp_ptr;
	return result;

}
bool MyStack::empty() const {
	return (top == NULL);
}
} /* namespace stacksavitch */

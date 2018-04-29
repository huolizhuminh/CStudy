/*
 * test.cpp
 *
 *  Created on: 2018年4月27日
 *      Author: anker
 */

#include<iostream>
#include "MyStack.h"
#include "MyQueue.h"
using namespace std;
using namespace stacksavitch;
void testStack();
void testQueue();
int main() {
	testQueue();
	return 0;
}
void testQueue() {
	MyQueue *queue = new MyQueue();
	queue->add('a');
	queue->add('b');
	queue->add('c');
	cout<<"end add<<endl";
	while (!queue->empty()) {
		cout<<"has data"<<endl;
		char pop_char = queue->remove();
		cout << pop_char << endl;

	}
}
void testStack() {
	MyStack *stack = new MyStack();

	stack->push('0');
	stack->push('1');
	stack->push('2');
	while (!stack->empty()) {
		char pop_char = stack->pop();
		cout << pop_char << endl;
	}
}

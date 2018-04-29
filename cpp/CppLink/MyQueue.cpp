/*
 * MyQueue.cpp
 *
 *  Created on: 2018年4月27日
 *      Author: anker
 */

#include "MyQueue.h"
#include<iostream>
using namespace std;
namespace stacksavitch {

MyQueue::MyQueue() :
		front(NULL), back(NULL) {

}

MyQueue::~MyQueue() {
	while (!empty()) {
		char a_char;
		a_char = remove();
	}
}
MyQueue::MyQueue(const MyQueue& aQueue) {
	front = NULL;
	back = NULL;
	QueueNode *aQueueNodeNext = aQueue.front;
	if (aQueueNodeNext != NULL) {
		front = new QueueNode();
		front->data = aQueueNodeNext->data;
		back = front;
	}
	while (aQueueNodeNext != NULL) {
		QueueNode *newNode = new QueueNode();
		newNode->data = aQueueNodeNext->data;
		aQueueNodeNext = aQueueNodeNext->link;
		back = newNode;
	}
}
void MyQueue::add(char item) {
	QueueNode *node = new QueueNode();
	node->data = item;
	if (front == NULL) {
		front = node;
		back = node;
	} else {
		back->link = node;
		back = node;
	}

}
char MyQueue::remove() {
	char a_char;
	a_char = front->data;
	QueueNode *temp = front;
	front = front->link;
	if (front == NULL) {
		back = NULL;
	}
	delete temp;
	return a_char;
}
bool MyQueue::empty() {
	return front == NULL;
}
} /* namespace stacksavitch */

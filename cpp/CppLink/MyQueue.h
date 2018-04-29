/*
 * MyQueue.h
 *
 *  Created on: 2018年4月27日
 *      Author: anker
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_

namespace stacksavitch {
struct QueueNode {
	char data;
	QueueNode*link;
};
class MyQueue {
public:
	MyQueue();
	virtual ~MyQueue();
	MyQueue(const MyQueue& aQueue);
	void add(char item);
	char remove();
	bool empty();
private:
	QueueNode *front;
	QueueNode*back;

};

} /* namespace stacksavitch */

#endif /* MYQUEUE_H_ */

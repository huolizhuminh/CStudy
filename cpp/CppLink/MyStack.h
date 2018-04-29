/*
 * Stack.h
 *
 *  Created on: 2018年4月27日
 *      Author: anker
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_

namespace stacksavitch {
struct StackFrame {
	char data;
	StackFrame *link;
};
class MyStack {
public:
	MyStack();
	virtual ~MyStack();
	//拷贝构造函数
	MyStack(const MyStack& a_stack);
	void push(char the_symbol);
	char pop();
	bool empty() const;
private:
	StackFrame* top;
};

} /* namespace stacksavitch */

#endif /* MYSTACK_H_ */

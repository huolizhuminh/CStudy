/*
 * Money.h
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */
#include <iostream>
#ifndef MONEY_H_
#define MONEY_H_

namespace std {

class Money {
public:
	friend Money operator +(const Money& money1, const Money& money2);
	friend Money operator -(const Money& money1, const Money& money2);
	friend Money operator -(const Money& money1);
	friend istream& operator >>(istream& ins, Money& money1);
	friend ostream& operator <<(ostream& outs, Money& money2);
	int getData();
	Money(int my_data);
	Money();
	virtual ~Money();
private:
	int data;
};

} /* namespace std */

#endif /* MONEY_H_ */

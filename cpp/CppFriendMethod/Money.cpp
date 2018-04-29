/*
 * Money.cpp
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */

#include "Money.h"
#include<iostream>
namespace std {

Money::Money() {

}
Money::Money(int moneydata) {
	// TODO Auto-generated constructor stub
	data = moneydata;
}
Money operator +(const Money& money1, const Money& money2) {
	Money resultMoney;
	resultMoney.data = money1.data + money2.data;
	return resultMoney;
}
Money operator -(const Money& money1, const Money& money2) {
	Money resultMoney;
	resultMoney.data = money1.data - money2.data;
	return resultMoney;
}
Money operator -(const Money& money1) {
	Money resultMoney;
	resultMoney.data = -money1.data;
	return resultMoney;
}
istream& operator >>(istream& ins,  Money& money1) {
	int temp_data;
	cout << "operator >> begin \n";
	ins >>money1.data;
	cout << "operator >> end \n";
//	money1.data = temp_data;
	return ins;
}
ostream& operator <<(ostream& outs,  Money& money2) {
	cout << "operator <<\n";
	outs << money2.data;
	return outs;
}
int Money::getData() {
	return data;
}
Money::~Money() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

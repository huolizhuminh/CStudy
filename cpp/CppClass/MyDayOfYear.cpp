/*
 * MyDayOfYear.cpp
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */

#include "MyDayOfYear.h"
#include <iostream>
namespace std {

MyDayOfYear::MyDayOfYear() {
	month=0;
	day=0;

}

MyDayOfYear::~MyDayOfYear() {
}

void MyDayOfYear::output() {
	cout << "month =" << month << ",day=" << day << endl;
}

} /* namespace std */

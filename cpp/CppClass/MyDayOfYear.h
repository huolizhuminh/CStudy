/*
 * MyDayOfYear.h
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */

#ifndef MYDAYOFYEAR_H_
#define MYDAYOFYEAR_H_

namespace std {

class MyDayOfYear {
public:
	MyDayOfYear();
	void output();
	int month;
	int day;
	virtual ~MyDayOfYear();
};

} /* namespace std */

#endif /* MYDAYOFYEAR_H_ */

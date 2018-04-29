/*
 * StringVar.h
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */
#include<iostream>
#ifndef STRINGVAR_H_
#define STRINGVAR_H_

namespace std {

class StringVar {
public:
	StringVar();
	StringVar(int size);
	StringVar(const char a[]);
	StringVar(const StringVar& string_object);
	int length() const;
	void input_line(istream& ins);
	friend ostream& operator<<(ostream& outs, const StringVar& the_string);
	virtual ~StringVar();
private:
	char *value;
	int max_length;
};

} /* namespace std */

#endif /* STRINGVAR_H_ */

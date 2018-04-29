/*
 * StringVar.cpp
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */

#include "StringVar.h"
#include <cstdlib>
#include <cstddef>
#include<cstring>
namespace std {

StringVar::StringVar() :
		max_length(100) {
	value = new char[max_length + 1];
	value[0] = '\0';
}

StringVar::~StringVar() {
	delete[] value;
}

StringVar::StringVar(int size) :
		max_length(size) {
	value = new char[max_length + 1];
	value[0] = '\0';
}

StringVar::StringVar(const char a[]) :
		max_length(strlen(a)) {
	value = new char[max_length + 1];
	strcpy(value, a);
}
StringVar::StringVar(const StringVar& string_object) :
		max_length(string_object.length()) {
	value = new char[max_length + 1];
	strcpy(value, string_object.value);
}
int StringVar::length() const {
	return strlen(value);
}
void StringVar::input_line(istream& ins) {
	ins.getline(value, max_length + 1);

}
ostream& operator<<(ostream& outs, const StringVar& the_string) {
	outs << the_string.value;
	return outs;
}

} /* namespace std */

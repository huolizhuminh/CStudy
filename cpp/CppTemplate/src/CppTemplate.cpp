//============================================================================
// Name        : CppTemplate.cpp
// Author      : minhui.zhu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "GenericList.h"
#include "GenericList.cpp";
using namespace listsavitch;
template<class T>
void swap_values(T& variable1, T&variable2) {
	T temp;
	temp = variable1;
	variable1 = variable2;
	variable2 = temp;
}
void test_templeta_method();
void test_templeta_class();
int main() {
	test_templeta_class();
	return 0;
}
void test_templeta_class() {
	GenericList<int> first_list(2);
	first_list.add(1);
	first_list.add(2);
	cout << first_list << endl;
	GenericList<char> second_list(10);
	second_list.add('A');
	second_list.add('B');
	second_list.add('C');
	cout << second_list << endl;

}
void test_templeta_method() {
	int integer1 = 1, integer2 = 2;
	cout << "integer1 :" << integer1 << "integer2 " << integer2 << endl;
	swap_values(integer1, integer2);
	cout << "integer1 :" << integer1 << "integer2 " << integer2 << endl;
	char char1 = 'A', char2 = 'B';
	cout << "char1 :" << char1 << "char2 " << char2 << endl;
	swap_values(char1, char2);
	cout << "char1 :" << char1 << "char2 " << char2 << endl;
}

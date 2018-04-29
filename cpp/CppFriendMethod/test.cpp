/*
 * test.cpp
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */

#include<iostream>
#include "Money.h"
#include "StringVar.h"
using namespace std;
void test_operator();
void is_test();
void virtual_test();
void conversation(int max_name_size);
void test_show();
void show_string(StringVar the_string);
namespace space1 {
void spacetestfun();
void fun1();
}
namespace space2 {
void spacetestfun();
void fun2();
}
void spacetest();
void limit_space_test();
int main() {
	//is_test();
	//	virtual_test();
	//test_show();
	limit_space_test();
	return 0;
}
void limit_space_test() {
//	using space1::fun1;
//	using space2::fun2;
//	fun1();
//	fun2();
	space1::fun1();
	space2::fun2();

}
void spacetest() {
	{
		using namespace space1;
		spacetestfun();
	}
	{
		using namespace space2;
		spacetestfun();
	}
}
namespace space1 {
void spacetestfun() {
	cout << "space1" << endl;
}
void fun1() {
	cout << "fun1" << endl;
}
}
namespace space2 {
void spacetestfun() {
	cout << "space2" << endl;
}
void fun2() {
	cout << "fun2" << endl;
}
}
void test_show() {
	StringVar greeting("Hello");
	show_string(greeting);
	cout << "after show_string:" << greeting << endl;
}
void show_string(StringVar the_string) {
	cout << "show_string ,the string is:" << the_string << endl;
}
void virtual_test() {
	using namespace std;
	conversation(30);
	cout << "End of demonstration.\n";

}
void conversation(int max_name_size) {
	using namespace std;
//	using namespace strvarsavitch;
	StringVar your_name(max_name_size), our_name("Borg");
	cout << "What is your name\n";
	your_name.input_line(cin);
	cout << "We ar" << our_name << endl;
	cout << "We will meet again" << your_name << endl;
}
void is_test() {
	Money myMoney(10);
	cout << "start test\n";
	cout << myMoney;
	cin >> myMoney;
	cout << "resut is :" << myMoney;
}
void test_operator() {
	Money myMoney(10), yourMoney(5);
	Money addMoney = myMoney + yourMoney;
	cout << addMoney.getData() << endl;
	Money minusMoney = myMoney - yourMoney;
	cout << minusMoney.getData();
}


/*
 * CPPClass.cpp
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */
#include <iostream>
#include "MyDayOfYear.h"
#include "Animal.h"
#include "Dog.h"
using namespace std;
void new_line();
void simpleClass();
int main() {
	Dog dog;
	dog.eat();
	dog.sleep();
	return 0;
}
void simpleClass() {
	MyDayOfYear today, birthday;
	cout << "Enter today's date:\n";
	cout << "Enter month as a number:";
	cin >> today.month;
	new_line();
	cout << "Enter the day of the month:";
	cin >> today.day;
	new_line();
	cout << "Enter your birthday:\n";
	cout << "Enter month as a number:";
	cin >> birthday.month;
	new_line();
	cout << "Enter the day of the month:";
	cin >> birthday.day;
	new_line();
	cout << "Today's date is\n";
	today.output();
	cout << "Your birthday is\n ";
	birthday.output();
	if (today.day == birthday.day && today.month == birthday.month) {
		cout << "Happy Birthday!\n";

	} else {
		cout << "Happy Unbirthday\n";
	}
}
void new_line() {
	char symbol;
	do {
		cin.get(symbol);
	} while (symbol != '\n');
}


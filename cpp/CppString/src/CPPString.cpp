//============================================================================
// Name        : CPPString.cpp
// Author      : minhui.zhu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<string>
using namespace std;
void new_line();
void read_and_clean(int& n);
void simpleString();
void stringToInt();
void simpleCppStr();
void strIO();
void cppstr_to_int();
int main() {
	cppstr_to_int();
	return 0;
}
void cppstr_to_int() {
	int i;
	double d;
	string s;
	i = stoi("35");
	d = stod("2.5");
	s = to_string(d * 2);
	cout << i << " " << d << " " << s;
}
void strIO() {
	string first_name, last_name, record_name;
	string motto = "Your records are our records";
	cout << "Enter your first and last name:\n";
	cin >> first_name >> last_name;
	new_line();
	record_name = last_name + "," + first_name;
	cout << "Your name in our records is:" << record_name << endl;
	cout << "our motto is\n" << motto << endl;
	cout << "please suggest a better motto:\n";
	getline(cin, motto);
	cout << "our new motto is" << endl << motto << endl;
}
void simpleCppStr() {
	string phrase;
	string adjective("friend"), noun("ants");
	string wish = "Bon appetite!";
	phrase = "I love " + adjective + " " + noun + "!";
	cout << phrase << endl << wish << endl;

}
void stringToInt() {
	int n;
	char ans;
	do {
		cout << "Enter an integer and press return:\n";
		read_and_clean(n);
		cout << "That string converts to the integer" << n << endl;
		cout << "Again?(yes/no)";
		cin >> ans;
		new_line();

	} while ((ans != 'n') && (ans != 'N'));
}
void read_and_clean(int& n) {
	const int ARRAY_SIZE = 6;
	char digit_string[ARRAY_SIZE];
	char next;
	cin.get(next);
	int index = 0;
	while (next != '\n') {
		if ((isdigit(next)) && (index < ARRAY_SIZE - 1)) {
			digit_string[index] = next;
			index++;
		}
		cin.get(next);
	}
	digit_string[index] = '\0';
	n = atoi(digit_string);
}
void new_line() {
	char symbol;
	do {
		cin.get(symbol);
	} while (symbol != '\n');
}
void simpleString() {
	char a[80];
	cout << "Enter some input:\n";
	cin.getline(a, 80);
	cout << a << "\nout of output\n";
}

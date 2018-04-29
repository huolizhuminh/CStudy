//============================================================================
// Name        : CPPIO.cpp
// Author      : minhui.zhu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void simpleIO();
void simpleApp();
void simpleIn();
void transferCpp();
void add_plus_plus_plus(ifstream& fin, ofstream& fout);
int main() {
	//simpleIO();
	//simpleApp();
	//simpleIn();
	transferCpp();
	return 0;
}
void transferCpp() {
	ifstream fin;
	ofstream fout;
	cout << "Begin editing files.\n";
	fin.open("infile.txt");
	if (fin.fail()) {
		cout << "input open failed";
		exit(1);
	}
	fout.open("outfile.txt");
	if (fout.fail()) {
		cout << "input open failed";
		exit(1);
	}
	add_plus_plus_plus(fin, fout);

}
void add_plus_plus_plus(ifstream& fin, ofstream& fout) {
	char next;

	while (!fin.eof()) {
		fin.get(next);
		cout<<next<<"\n";
		if (next == 'C'||next == 'c') {
			cout<<"equal";
			fout << "C++";
		} else {
			fout << next;
		}

	}
}
void simpleIn() {
	ifstream in_stream;
	in_stream.open("outfile.txt");
	int count = 0, next;
	while (in_stream >> next) {
		count++;
		cout << next << endl;
	}

	in_stream.close();
	cout << count;
}
void simpleApp() {
	ifstream in_stream;
	ofstream out_stream;
	out_stream.open("outfile.txt", ios::app);
	out_stream << "The sum of the first 3\n" << "is" << endl;
	in_stream.close();
	out_stream.close();
}
void simpleIO() {
	ifstream in_stream;
	//	ofstream out_stream;
	in_stream.open("outfile.txt");
	//	out_stream.open("outfile.txt");
	int first = 0, second = 0, third = 1;
	string data = "zhuminh";
	in_stream >> first;
	cout << first;
	//	out_stream << "The sum of the first 3\n" << "is" << (first + second + third)
	//			<< endl;
	in_stream.close();
	//	out_stream.close();
}

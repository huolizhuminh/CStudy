//============================================================================
// Name        : CPPContainer.cpp
// Author      : minhui.zhu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::map;
using std::string;
using std::find;
using std::cin;
void test_algorithm() {
	vector<char> line;
	cout << "Enter a line of text:\n";
	char next;
	cin.get(next);
	while(next!='\n'){
		line.push_back(next);
		cin.get(next);
	}
	vector<char>::iterator where;
	where=find(line.begin(),line.end(),'e');
	vector<char>::iterator p;
	for(p=line.begin();p!=where;p++){
		cout<<*p;
	}
	cout<<endl;
	for(p=where;p!=line.end();p++){
		cout<<*p;
	}
	cout<<endl;

}

void testMap() {
	map<string, string> planets;
	planets["Mercury"] = "Hot planet";
	planets["Earth"] = "Home";
	cout << "Entry for Mercury" << planets["Mercury"] << endl;
	if (planets.find("xx") == planets.end()) {
		cout << "xx is not in planet" << endl;
	}
	for (auto p : planets) {
		cout << " first:" << p.first << " second:" << p.second << endl;
	}

}
void testSet() {
	set<char> s;
	s.insert('A');
	s.insert('B');
	s.insert('B');
	s.insert('C');
	s.insert('D');
	s.insert('D');
	cout << "The set contains:\n";
	set<char>::const_iterator p;
	for (p = s.begin(); p != s.end(); p++) {
		cout << *p << " ";
	}
	cout << endl;
	cout << "remove C\n";
	s.erase('C');
//	for (p = s.begin(); p != s.end(); p++) {
//		cout << *p << " ";
//	}
	for (auto p : s) {
		cout << p << " ";
	}
	cout << endl;
}
void testVector() {
	vector<int> container;
	for (int i = 1; i <= 4; i++) {
		container.push_back(i);
	}
	cout << "Here is what is in the container:\n";
	vector<int>::iterator p;
	for (p = container.begin(); p != container.end(); p++) {
		cout << *p << " ";
	}
	cout << endl;
	cout << "Setting entries to 0:\n";
	for (p = container.begin(); p != container.end(); p++) {
		*p = 0;
	}
	cout << "container now contains:\n";
	for (p = container.begin(); p != container.end(); p++) {
		cout << *p << " ";
	}
	cout << endl;
}
int main() {
	test_algorithm();
	return 0;
}


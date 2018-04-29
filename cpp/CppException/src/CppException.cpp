//============================================================================
// Name        : CppException.cpp
// Author      : minhui.zhu
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "NegativeMilk.h"
#include "NoMilk.h"
using namespace std;
using namespace salesavitch;
int main() {
	int donuts, milk;
	double dpg;
	try {
		cout << "Enter number of donuts:\n";
		cin >> donuts;
		cout << "Enter number of glasses of milk:\n ";
		cin >> milk;
		if (milk == 0) {
			throw NoMilk(donuts);
		}
		if (milk < 0) {
			throw NegativeMilk(donuts);
		}
		dpg = donuts / static_cast<double>(milk);
		cout << "donuts is " << donuts << " milk:" << milk << "dpg :" << dpg
				<< endl;
	} catch (NoMilk & nm) {
		cout << "no milk " << nm.get_donuts() << endl;
	} catch (NegativeMilk & ngm) {
		cout << "negative milk" << ngm.get_donuts() << endl;
	} catch (...) {
		cout << "no reason" << endl;
	}
	return 0;
}

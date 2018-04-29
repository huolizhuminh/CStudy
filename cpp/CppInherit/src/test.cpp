/*
 * test.cpp
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */
#include<iostream>
#include "sale.h"
#include "discountsale.h"
using namespace std;
using namespace salesavitch;
int main() {
	Sale simple(10.00);
	DiscountSale discount(11.00, 10);
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	if (discount < simple) {
		cout << "discounted item cheaper.\n";
		cout << "Saving is $" << simple.savings(discount) << endl;

	} else {
		cout << "Discounted item is not cheaper.\n";
	}
	return 0;
}

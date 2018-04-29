/*
 * Sale.cpp
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#include "Sale.h"

namespace salesavitch {

Sale::Sale() :
		price(0) {

}

Sale::~Sale() {
}
Sale::Sale(double the_price) :
		price(the_price) {

}
double Sale::bill() const {
	cout<<"sale bill"<<endl;
	return price;
}
double Sale::savings(const Sale& other) const {
	return (bill() - other.bill());
}
bool operator<(const Sale& first, const Sale& second) {
	return (first.bill() < second.bill());
}
} /* namespace salesavitch */

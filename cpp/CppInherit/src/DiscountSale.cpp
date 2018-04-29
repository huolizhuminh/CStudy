/*
 * DiscountSale.cpp
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#include "DiscountSale.h"

namespace salesavitch {

DiscountSale::DiscountSale() :
		Sale(), discount(0) {

}

DiscountSale::~DiscountSale() {
	// TODO Auto-generated destructor stub
}
DiscountSale::DiscountSale(double the_price, double the_discount) :
		Sale(the_price), discount(the_discount) {

}
double DiscountSale::bill() const {
	cout<<"DiscountSale bill"<<endl;
	double fraction = discount / 100;
	return (1 - fraction) * price;
}
} /* namespace salesavitch */

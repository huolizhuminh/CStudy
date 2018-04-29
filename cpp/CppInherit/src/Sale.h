/*
 * Sale.h
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#ifndef SALE_H_
#define SALE_H_

#include <iostream>;
using namespace std;
namespace salesavitch {

class Sale {
public:
	Sale();
	Sale(double the_price);
	virtual double bill() const;
	//double bill() const;
	double savings(const Sale& other) const;
	virtual ~Sale();
protected:
	double price;
};
bool operator<(const Sale& first, const Sale& second);

} /* namespace salesavitch */

#endif /* SALE_H_ */

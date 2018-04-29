/*
 * DiscountSale.h
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#ifndef DISCOUNTSALE_H_
#define DISCOUNTSALE_H_

#include "Sale.h"

namespace salesavitch {

class DiscountSale: public Sale {
public:
	DiscountSale();
	virtual ~DiscountSale();
	DiscountSale(double the_price, double the_discount);
	//virtual double bill() const;
	double bill() const;
protected:
	double discount;
};

} /* namespace salesavitch */

#endif /* DISCOUNTSALE_H_ */

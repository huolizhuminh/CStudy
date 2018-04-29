/*
 * NegativeMilk.h
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#ifndef NEGATIVEMILK_H_
#define NEGATIVEMILK_H_

namespace salesavitch {

class NegativeMilk {
public:
	NegativeMilk();
	NegativeMilk(int the_count);
	int get_donuts();
	virtual ~NegativeMilk();
private:
	int count;
};

} /* namespace salesavitch */

#endif /* NEGATIVEMILK_H_ */

/*
 * NoMilk.h
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#ifndef NOMILK_H_
#define NOMILK_H_

namespace salesavitch {

class NoMilk {
public:
	NoMilk();
	NoMilk(int this_count);
	virtual ~NoMilk();
	int get_donuts();
private:
	int count;
};

} /* namespace salesavitch */

#endif /* NOMILK_H_ */

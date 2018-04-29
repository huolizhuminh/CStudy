/*
 * Dog.h
 *
 *  Created on: 2018年4月25日
 *      Author: anker
 */

#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

namespace std {

class Dog: public Animal {
public:
	Dog();
	void sleep();
	virtual ~Dog();
};

} /* namespace std */

#endif /* DOG_H_ */

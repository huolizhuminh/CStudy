/*
 * NoMilk.cpp
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#include "NoMilk.h"

namespace salesavitch {

NoMilk::NoMilk() :
		count(0) {

}
NoMilk::NoMilk(int this_count) :
		count(this_count) {

}
NoMilk::~NoMilk() {
}
int NoMilk::get_donuts() {
	return count;
}
} /* namespace salesavitch */

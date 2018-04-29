/*
 * NegativeMilk.cpp
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#include "NegativeMilk.h"

namespace salesavitch {
NegativeMilk::NegativeMilk(int the_count):count(the_count){

}
NegativeMilk::NegativeMilk() :
		count(0) {

}
int NegativeMilk::get_donuts() {
	return count;
}
NegativeMilk::~NegativeMilk() {
}

} /* namespace salesavitch */

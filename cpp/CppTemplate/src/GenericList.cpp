/*
 * GenericList.cpp
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */
#ifndef GENERICLIST_CPP
#define GENERICLIST_CPP
#include "GenericList.h"
#include<iostream>
#include<cstdlib>
using namespace std;
namespace listsavitch {
template<class ItemType>
GenericList<ItemType>::GenericList(int max) :
		max_length(max), current_length(0) {
	item = new ItemType[max];
}
template<class ItemType>
GenericList<ItemType>::~GenericList() {
	delete[] item;
}
template<class ItemType>
int GenericList<ItemType>::length() const {
	return current_length;
}
template<class ItemType>
void GenericList<ItemType>::add(ItemType new_item) {
	if (full()) {
		cout << "error adding to a full list.\n";
		exit(1);
	} else {
		item[current_length] = new_item;
		current_length = current_length + 1;
	}
}
template<class ItemType>
bool GenericList<ItemType>::full() const {
	return current_length == max_length;
}
template<class ItemType>
void GenericList<ItemType>::erase() {
	current_length = 0;

}

template<class ItemType>
ostream& operator <<(ostream& outs, const GenericList<ItemType>& the_list) {
	for (int i = 0; i < the_list.current_length; i++) {
		outs << the_list.item[i] << endl;
	}
	return outs;
}

} /* namespace listsavitch */
#endif

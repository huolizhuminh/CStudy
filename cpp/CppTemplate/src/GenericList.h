/*
 * GenericList.h
 *
 *  Created on: 2018年4月28日
 *      Author: anker
 */

#ifndef GENERICLIST_H_
#define GENERICLIST_H_
#include<iostream>
using namespace std;
namespace listsavitch {
template<class ItemType>
class GenericList {
public:
	GenericList(int max);
	virtual ~GenericList();
	int length() const;
	void add(ItemType new_item);
	bool full() const;
	void erase();
	template<class B>
	friend ostream& operator<<(ostream& out, const GenericList<B>& the_list);
private:
	ItemType*item;
	int max_length;
	int current_length;
};

} /* namespace listsavitch */

#endif /* GENERICLIST_H_ */

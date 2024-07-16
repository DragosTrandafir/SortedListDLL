#pragma once
#include "SortedIteratedList.h"

//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIteratedList;
private:
	const SortedIteratedList& list;
	ListIterator(const SortedIteratedList& list);

	PNod current;
	//TODO - Representation
public:
	void first();
	void next();
	void prev();
	bool valid() const;
    TComp getCurrent() const;
};



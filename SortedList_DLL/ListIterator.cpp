#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	//TODO - Implementation
	this->current = list.head;
	
}

void ListIterator::first(){
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	//TODO - Implementation
	this->current = this->list.head;
}

void ListIterator::next(){
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	else {
		this->current = current->next();
	}
}

void ListIterator::prev()
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	if (!valid()) {
		throw exception();
	}
	else {
		this->current = current->prev();
	}
}

bool ListIterator::valid() const{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	//TODO - Implementation
	return (this->current != nullptr);
}

TComp ListIterator::getCurrent() const{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	//TODO - Implementation
	if (!valid()) {
		throw exception();
	}
	else {
		return this->current->element();
	}
}



#include "SortedIteratedList.h"
#include "ListIterator.h"
#include <exception>
#include <iostream>

using namespace std;

Node::Node(TComp e, PNod urm, PNod prev)
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	this->e = e;
	this->nextNode = urm;
	this->prevNode = prev;
}

TComp Node::element() 
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return this->e;
}

PNod Node::next() 
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return this->nextNode;
}

PNod Node::prev() 
{
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return this->prevNode;
}

SortedIteratedList::SortedIteratedList(Relation r) {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	//TODO - Implementation
	this->rel = r;
	this->head = nullptr;
	this->tail = nullptr;
}


int SortedIteratedList::size() const {
	// BC:Tita(1) WC:Tita(n) Overall:O(n)
	//TODO - Implementation
	int nr = 0;
	PNod p = this->head;
	while (p != nullptr) {
		nr++;
		p = p->next();
	}
	return nr;
}

bool SortedIteratedList::isEmpty() const {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	return (this->head == nullptr && this->tail==nullptr);
}

ListIterator SortedIteratedList::first() const {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	//TODO - Implementation
	return ListIterator(*this);
}

TComp SortedIteratedList::getElement(ListIterator poz) const {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)

	//check if the list isempty or the iterator is not valid
	if (this->isEmpty() || !poz.valid())
		throw exception(); 

	//retur the element pointed to by the iterator's current node
	return poz.getCurrent();
}

TComp SortedIteratedList::remove(ListIterator& poz) {
	// BC:Tita(1) WC:Tita(1) Overall:O(1)
	if (!poz.valid())
		throw exception();

	TComp removedElement = poz.getCurrent(); // get the element which needs to be removed 
	PNod current = poz.current; // get the node of the iterator
	PNod previous = current->prevNode;   // get the next and previous nodes
	PNod next = current->nextNode;

	poz.next(); // move the iterator to the next element before removal, because otherwise it would point to the deleted node

	if (previous == nullptr) { // iff the pozition is the first, we just need to update the head
		this->head = next;
	}
	else {
		previous->nextNode = next; // else link the previous to the next
	}

	if (next == nullptr) { // the sam e for the tail
		this->tail = previous;
	}
	else {
		next->prevNode = previous;
	}

	delete current; // here we actually delete the node from the memory

	return removedElement;


}

ListIterator SortedIteratedList::search(TComp e) const{
	// BC:Tita(1) WC:Tita(n) Overall:O(n)

	//TODO - Implementation
	PNod p = this->head;

	ListIterator iterator(*this); // create an iterator over the list
	while (p != nullptr && rel(p->element(), e)) { // while we still elements and the relation is respected
		if (p->element() == e) {
			iterator.current = p;
			return iterator;
		}
		else {
			p = p->next();
		}
	}

	iterator.current = nullptr;
	return iterator;// return the iterator object which stores our node/ an invalid iterator
}

void SortedIteratedList::add(TComp e) {
	// BC:Tita(1) WC:Tita(n) Overall:O(n)

	PNod newNode = new Node(e, nullptr, nullptr);

	// if the DLL is empty or e is in relation (smaller) than e
	if (this->isEmpty() || !rel(this->head->element(), e)) { 
		newNode->nextNode = this->head;
		if (this->head != nullptr) {
			this->head->prevNode = newNode; // add at the beginning
		}
		this->head = newNode; // update 6he head either way
	}
	else {
		// if we have nodes in the list
		PNod current = this->head;
		// we traverse prim the beggining to the end or until the relation is not respected
		while (current->next() != nullptr && rel(current->next()->element(), e)) {
			current = current->next();
		}
		newNode->nextNode = current->nextNode;
		newNode->prevNode = current;// form the links for the new node

		current->nextNode = newNode;// update the next node for the current

		if (newNode->nextNode != nullptr) {
			newNode->nextNode->prevNode = newNode; // update the prev node for the next node
		}
	}
}

SortedIteratedList::~SortedIteratedList() {
	// BC:Tita(1) WC:Tita(n) Overall:O(n)
	//TODO - Implementation
	while (head != nullptr) {
		PNod p = head;
		head = head->nextNode;
		delete p;
	}
}



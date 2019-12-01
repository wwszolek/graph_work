#include "list.h"

#include <string>
#include <iostream>


template <int node_size>
list<node_size>::iterator::iterator(node<node_size>* p) :p(p) {}

template <int node_size>
typename list<node_size>::iterator& list<node_size>::iterator::operator++() {
	p = p->next;
	return *this;
}

template <int node_size>
typename list<node_size>::iterator list<node_size>::iterator::operator++(int) {
	iterator tmp = *this;
	++*this;
	return tmp;
}

template <int node_size>
bool list<node_size>::iterator::operator==(const iterator& other)const {
	return p == other.p;
}

template <int node_size>
bool list<node_size>::iterator::operator!=(const iterator& other)const {
	return p != other.p;
}

template <int node_size>
node<node_size>*& list<node_size>::iterator::operator*() {
	return p;
}

template <int node_size>
node<node_size>* list<node_size>::iterator::operator->() {
	return p;
}

template <int node_size>
typename list<node_size>::iterator list<node_size>::begin() {
	return list<node_size>::iterator(_head);
}

template <int node_size>
typename list<node_size>::iterator list<node_size>::end() {
	return list<node_size>::iterator(NULL);
}

template <int node_size>
list<node_size>::list() : _head(NULL) {}

template <int node_size>
list<node_size>::~list() {
	while (_head)
		delHead();
}

template <int node_size>
list<node_size>::list(const list<node_size>& other):_head(NULL) {
	node<node_size>* p = other._head;
	while (p) {
		this->queue(p->values);
		p = p->next;
	}
}

template <int node_size>
list<node_size>& list<node_size>::operator==(const list<node_size>& other) {
	node<node_size>* p = other._head;
	while (p) {
		this->queue(_head->values);
		p = p->next;
	}

	return *this;
}

template <int node_size>
void list<node_size>::insertHead(const int (&_values)[node_size]) {
	node<node_size>* p = new node<node_size>;
	for (int i = 0; i < node_size; i++)
		p->values[i] = _values[i];
	p->next = _head;
	_head = p;
}

template <int node_size>
void list<node_size>::insertSorted(const int(&_values)[node_size],int sort_by) {
	node<node_size>* p = new node<node_size>;
	for (int i = 0; i < node_size; i++)
		p->values[i] = _values[i];

	insertHead(_values);
	node<node_size>*k = _head;
	
	while (k) {
		if (!k->next || k->next->values[sort_by] > p->values[sort_by]) {
			p->next = k->next;
			k->next = p;
			break;
		}
		k = k->next;
	}

	delHead();
}

template <int node_size>
void list<node_size>::delHead() {
	if (_head != NULL) {
		node<node_size>*p = _head;
		_head = _head->next;
		delete p;
	}
}

template <int node_size>
void list<node_size>::show() {
	node<node_size>*p = _head;
	while (p != NULL) {
		std::string print = "(";
		for (int i = 0; i < node_size; i++)
			print += std::to_string(p->values[i]) + ",";
		print.pop_back();
		print += ")->";
		std::cout << print;
		p = p->next;
	}
	std::cout << "||";
}

template <int node_size>
void list<node_size>::queue(const int(&_values)[node_size]) {
	node<node_size>* p = _head;
	node<node_size>* n = new node<node_size>;
	n->next = NULL;

	for (int i = 0; i < node_size; i++)
		n->values[i] = _values[i];
	if (p) {
		while (p->next)
			p = p->next;

		p->next = n;
	}
	else {
		_head = n;
	}
}

template <int node_size>
int* list<node_size>::pop(){
	if (_head) {
		int*values = new int[node_size];
		for (int i = 0; i < node_size; i++) {
			values[i] = _head->values[i];
		}
		delHead();
		return values;
	}
	else return NULL;
}

template <int node_size>
int* list<node_size>::top() {
	if (_head) {
		int*values = new int[node_size];
		for (int i = 0; i < node_size; i++) {
			values[i] = _head->values[i];
		}
		return values;
	}
	else return NULL;
}

template <int node_size>
bool list<node_size>::isempty() {
	return _head == NULL;
}

template <int node_size>
int list<node_size>::len() {
	int length = 0;
	auto it = begin();
	while (it != end()) {
		it++;
		length++;
	}
	return length;
}

template <int node_size>
void list<node_size>::replaceAfter(node<node_size>*p) {
	if (p&&p->next&&p->next->next) {
		auto*k = p->next;
		p->next = k->next;
		k->next = p->next->next;
		p->next->next = k;
	}
}

template <int node_size>
void list<node_size>::bubbleSort(int sort_by){
	if (!isempty()) {
		bool Done = false;
		insertHead(_head->values);
		while (!Done) {
			Done = true;
			auto *p = _head;
			while (p&&p->next&&p->next->next) {
				if (p->next->values[sort_by] > p->next->next->values[sort_by]) {
					replaceAfter(p);
					Done = false;
				}
				p = p->next;
			}
		}
		delHead();
	}
}

template class list<1>;
template class list<2>;
template class list<3>;
#include "list.h"

#include <string>
#include <iostream>

template <int node_size>
list<node_size>::list() : _head(NULL) {}

template <int node_size>
list<node_size>::~list() {
	while (_head)
		delHead();
}


template <int node_size>
void list<node_size>::insertHead(const int (&_values)[node_size]) {
	_list_node<node_size>* p = new _list_node<node_size>;
	for (int i = 0; i < node_size; i++)
		p->values[i] = _values[i];
	p->next = _head;
	_head = p;
}

template <int node_size>
void list<node_size>::delHead() {
	if (_head != NULL) {
		_list_node<node_size>*p = _head;
		_head = _head->next;
		delete p;
	}
}

template <int node_size>
void list<node_size>::show() {
	_list_node<node_size>*p = _head;
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
void list<node_size>::push(const int(&_values)[node_size]) {
	_list_node<node_size>* p = _head;
	if (p) {
		while (p->next)
			p = p->next;

		_list_node<node_size>* n = new _list_node<node_size>;
		for (int i = 0; i < node_size; i++)
			n->values[i] = _values[i];
		n->next = NULL;
		p->next = n;
	}
	else {
		insertHead(_values);
	}
}

template <int node_size>
int* list<node_size>::pop() {
	int*values = new int[node_size];
	for (int i = 0; i < node_size; i++)
		values[i] = _head->values[i];
	delHead();
	return values;
}

template <int node_size>
bool list<node_size>::isempty() {
	return _head == NULL;
}

template class list<1>;
template class list<2>;
template class list<3>;
#include "adj_list.h"

#include <string>
#include <fstream>
#include <iostream>

#include "list.h"

adj_list::adj_list() : _list(NULL), _size(-1) {}
adj_list::adj_list(const std::string& filename) {
	std::fstream file(filename);
	file >> _size;

	_list = new list<2>[_size];
	for (int i = 0; i < _size; i++)
		_list[i] = list<2>();

	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++) {
			int v;
			file >> v;
			if (v)
				_list[i].insertHead({j, v});
		}

}

adj_list::~adj_list() {
	if (_list)
		delete[] _list;
}

void adj_list::show() {
	for (int i = 0; i < _size; i++) {
		std::cout << i << "->";
		_list[i].show();
		std::cout << std::endl;
	}
}

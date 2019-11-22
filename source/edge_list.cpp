#include "edge_list.h"

#include <string>
#include <fstream>

edge_list::edge_list() :_list(), _size(-1) {}
edge_list::edge_list(const std::string& filename) {
	std::fstream file(filename);

	file >> _size;

	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			int v;
			file >> v;
			if (v)
				_list.insertHead({ i, j, v });
		}
	}
}

void edge_list::show() {
	_list.show();
}
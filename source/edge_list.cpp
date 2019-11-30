#include "edge_list.h"

#include <string>
#include <fstream>

edge_list::edge_list() :_list(), _size(-1) {}
edge_list::edge_list(const std::string& filename,bool t):_top_only(t) {
	std::fstream file(filename);

	file >> _size;

	if (t) {
		for (int i = 0; i < _size; i++) {
			for (int j = i; j < _size; j++) {
				int v;
				file >> v;
				if (v)
					_list.insertHead({ i, j, v });
			}
		}
	}
	else {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				int v;
				file >> v;
				if (v)
					_list.insertHead({ i, j, v });
			}
		}
	}
}

void edge_list::show() {
	_list.show();
}
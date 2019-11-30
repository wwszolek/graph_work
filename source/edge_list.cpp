#include "edge_list.h"

#include <string>
#include <fstream>

edge_list::edge_list() :_list(), _size(-1) {}
edge_list::edge_list(const std::string& filename,bool t):_top_only(t) {
	std::fstream file(filename);

	file >> _size;

	if (t) {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++) {
				int v;
				file >> v;
				if (v && j > i)
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

edge_list::edge_list(const list<3>& list,bool t): _list(list),_top_only(t) {}

void edge_list::show() {
	_list.show();
}

edge_list edge_list::kruskal_spanning() {
	_list.bubbleSort(2);

	int* used = new int[_size];
	int* forest = new int[_size];
	int forest_i = 0;
	for (int i = 0; i < _size; i++) {
		used[i] = false;
	}

	list<3> span;

	auto it = _list.begin();
	while (*it) {
		int left=it->values[0];
		int right = it->values[1];
		if (!used[left] && !used[right]) {
			forest[left] = forest_i;
			forest[right] = forest_i;
			forest_i++;
			used[left] = true;
			used[right] = true;
			span.insertHead(it->values);
		}
		else if (used[left] && !used[right]) {
			forest[right] = forest[left];
			used[right] = true;
			span.insertHead(it->values);
		}
		else if (!used[left] && used[right]) {
			//blizniaczo do wyzej
			forest[left] = forest[right];
			used[left] = true;
			span.insertHead(it->values);
		}
		it++;
	}

	return edge_list(span,true);
}
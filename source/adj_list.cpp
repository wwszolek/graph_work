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

int adj_list::getSize() {
	return _size;
}

void adj_list::show() {
	for (int i = 0; i < _size; i++) {
		std::cout << i << "->";
		_list[i].show();
		std::cout << std::endl;
	}
}

list<1> adj_list::getAdjVert(int v) {
	_list_node<2>*p = _list[v]._head;
	list<1> q;
	while(p){
		q.push({ p->values[0] });
		p = p->next;
	}
	return q;
}

int adj_list::getDist(int from, int to) {
	auto p = _list[from]._head;
	while (p) {
		if (p->values[0] == to)
			return p->values[1];
		p = p->next;
	}
}

void adj_list::breadth_first_search(int start,int*& pi,int*& d) {
	if (!pi && !d) {
		int* color = new int[_size];
		for (int i = 0; i < _size; i++)color[i] = 0;
		pi = new int[_size];
		d = new int[_size];

		list<1> q;
		q.push({ start });
		color[start] = 1;
		pi[start] = -1;
		d[start] = 0;

		while (!q.isempty()) {
			int active = *q.pop();

			list<1> adj_vert = getAdjVert(active);
			while (!adj_vert.isempty()) {
				int adj = *adj_vert.pop();

				if (color[adj] == 0) {
					q.push({ adj });
					color[adj] = 1;
					pi[adj] = active;
					d[adj] = d[active] + getDist(active,adj);
				}
			}
			color[active] = 2;
		}

		std::cout << "color" << std::endl;
		for (int i = 0; i < _size; i++) {
			std::cout << color[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "pi" << std::endl;
		for (int i = 0; i < _size; i++) {
			std::cout << pi[i] << " ";
		}
		std::cout << std::endl;

		std::cout << "d" << std::endl;
		for (int i = 0; i < _size; i++) {
			std::cout << d[i] << " ";
		}
		std::cout << std::endl;
	}

}
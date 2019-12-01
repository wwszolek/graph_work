#include "adj_list.h"

#include <string>
#include <fstream>
#include <iostream>

#include "list.h"
#include "edge_list.h"

adj_list::adj_list(int size) : _size(size) {
	_list = new list<2>[_size];
	for (int i = 0; i < _size; i++)
		_list[i] = list<2>();
}
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

void adj_list::addEdge(int from, int to, int weight) {
	_list[from].insertHead({ to,weight });
}

list<1> adj_list::getAdjVert(int v) {
	auto p = _list[v].begin();
	list<1> q;
	while(*p){
		q.queue({ p->values[0] });
		p++;
	}
	return q;
}

int adj_list::getDist(int from, int to) {
	auto p = _list[from].begin();
	while (*p) {
		if (p->values[0] == to)
			return p->values[1];
		p++;
	}
	return -1;
}

void adj_list::breadth_first_search(int start,int*& pi,int*& d) {
	if (!pi && !d) {
		int* color = new int[_size];
		for (int i = 0; i < _size; i++)
			color[i] = 0;
		pi = new int[_size];
		d = new int[_size];

		list<1> q;
		q.queue({ start });
		color[start] = 1;
		pi[start] = -1;
		d[start] = 0;

		while (!q.isempty()) {
			int active = q.pop()[0];

			list<1> adj_vert = getAdjVert(active);
			while (!adj_vert.isempty()) {
				int adj = adj_vert.pop()[0];

				if (color[adj] == 0) {
					q.queue({ adj });
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

		delete[] color;
	}

}

void adj_list::_dfs(int from, int active, int*& color, int*& pi, int*& d) {
	color[active] = 1;
	pi[active] = from;
	if(from>=0)
		d[active] = d[from] + getDist(from, active);
	else
		d[active] = 0;

	list<1> adj_vert = getAdjVert(active);
	while (!adj_vert.isempty()) {
		int adj = adj_vert.pop()[0];

		if (color[adj] == 0) {
			_dfs(active, adj, color, pi, d);
		}
	}
	color[active] = 2;

}

void adj_list::depth_first_search(int start, int*& pi, int*& d) {
	if (!pi && !d) {
		int* color = new int[_size];
		for (int i = 0; i < _size; i++)
			color[i] = 0;
		pi = new int[_size];
		d = new int[_size];

		_dfs(-1, start, color, pi, d);


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

		delete[] color;
	}
}

adj_list adj_list::prim_spanning() {
	adj_list span(_size);

	if (!_list->isempty()) {
		edge_list edges;
		list<1> added_nodes;
		added_nodes.insertHead({ 0 });
		for (auto it = _list[0].begin(); it != _list[0].end(); it++)
			edges.addEdgeSorted(0,it->values[0],it->values[1]);

		bool*visited = new bool[_size];
		for (int i = 0; i < _size; i++)
			visited[i] = false;

		while (added_nodes.len() < _size) {
			int* e = edges.popEdge();

			if (!visited[e[1]]) {
				added_nodes.insertHead({ e[1] });
				visited[e[1]] = true;
				span.addEdge(e[0], e[1], e[2]);

				for (auto it = _list[e[1]].begin(); it != _list[e[1]].end(); it++)
					edges.addEdgeSorted(e[1],it->values[0],it->values[1]);
			}
		}
	}

	return span;
}
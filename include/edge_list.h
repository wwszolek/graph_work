#ifndef EDGE_LIST_H
#define EDGE_LIST_H

#include <string>

#include "list.h"

class edge_list {
private:
	list<3> _list;
	bool _top_only;
	int _size;
public:
	edge_list();
	edge_list(const std::string&,bool);
	edge_list(const list<3>&,bool);

	void addEdge(int, int, int);
	void addEdgeSorted(int, int, int);
	int* popEdge();

	edge_list kruskal_spanning();
	void show();
	void sortByWeight();
};

#endif
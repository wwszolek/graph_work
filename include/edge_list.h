#ifndef EDGE_LIST_H
#define EDGE_LIST_H

#include <string>

#include "list.h"

class edge_list {
private:
	list<3> _list;
	int _size;
public:
	edge_list();
	edge_list(const std::string&);


	void show();
};

#endif
#ifndef ADJ_LIST_H
#define ADJ_LIST_H

#include <string>
#include "list.h"

class adj_list {
private:
	list<2>* _list;
	int _size;

public:
	adj_list();
	adj_list(const std::string&);

	~adj_list();

	void show();
};

#endif
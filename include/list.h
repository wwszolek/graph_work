#ifndef LIST_H
#define LIST_H

template<int node_size>
struct _list_node {
	_list_node<node_size>* next;
	int values[node_size];
};

template<int node_size>
class list {
private:
	_list_node<node_size>* _head;

public:
	list();
	~list();

	void insertHead(const int(&)[node_size]);
	void delHead();

	void show();
};

#endif
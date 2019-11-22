#ifndef LIST_H
#define LIST_H

template<int node_size>
struct _list_node {
	_list_node<node_size>* next;
	int values[node_size];
};

template<int node_size>
class list {
public:
	_list_node<node_size>* _head;

public:
	list();
	~list();
	list(const list<node_size>&);
	list<node_size>& operator==(const list<node_size>&);

	void insertHead(const int(&)[node_size]);
	void delHead();

	void push(const int(&)[node_size]);
	const int* pop();
	const int* top();

	bool isempty();
	
	void show();
};

#endif
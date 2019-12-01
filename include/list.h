#ifndef LIST_H
#define LIST_H

template<int node_size>
struct node {
	node<node_size>* next;
	int values[node_size];

};

template<int node_size>
class list {
	class iterator {
		node<node_size>* p;

	public:
		iterator(node<node_size>*);
		iterator& operator++();
		iterator operator++(int);
		bool operator==(const iterator& other)const;
		bool operator!=(const iterator& other)const;

		node<node_size>*& operator*();
		node<node_size>* operator->();
	};
public:
	iterator begin();
	iterator end();
	
private:
	node<node_size>* _head;

public:
	list();
	~list();
	list(const list<node_size>&);
	list<node_size>& operator==(const list<node_size>&);

	void insertHead(const int(&)[node_size]);
	void insertSorted(const int(&)[node_size], int);
	void delHead();

	void queue(const int(&)[node_size]);
	int* pop();
	int* top();

	bool isempty();
	int len();
	
	void replaceAfter(node<node_size>*);
	void bubbleSort(int);

	void show();
};

#endif
#ifndef ADJ_LIST_H
#define ADJ_LIST_H

#include <string>
#include "list.h"

class adj_list{
private:
	list<2>* _list;
	int _size;

public:
	adj_list(int);
	adj_list(const std::string&);

	~adj_list();

	int getSize();

	void show();

	void addEdge(int, int, int);

	list<1> getAdjVert(int);
	int getDist(int, int);

	void breadth_first_search(int,int*&,int*&);

private: 
	void _dfs(int, int, int*&, int*&, int*&);
public:
	void depth_first_search(int, int*&, int*&);

	adj_list prim_spanning();
};

#endif
#ifndef ADJ_MATRIX_H
#define ADJ_MATRIX_H

#include <string>

class adj_matrix {
private:
	int**_matrix;
	int _size;
public:
	adj_matrix();
	adj_matrix(const std::string&);

	~adj_matrix();

	void show();

};

#endif
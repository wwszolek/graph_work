#include "adj_matrix.h"

#include <string>
#include <fstream>
#include <iostream>

adj_matrix::adj_matrix() :_matrix(NULL), _size(-1) {}

adj_matrix::adj_matrix(const std::string& filename) {
	std::fstream file(filename);

	file >> _size;

	_matrix = new int*[_size];
	for (int i = 0; i < _size; i++)
		_matrix[i] = new int[_size];

	for (int i = 0; i < _size; i++)
		for (int j = 0; j < _size; j++)
			file >> _matrix[i][j];

}

adj_matrix::~adj_matrix() {
	if (_matrix) {
		for (int i = 0; i < _size; i++)
			delete[] _matrix[i];
		delete[] _matrix;
	}

}

void adj_matrix::show() {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++)
			std::cout << _matrix[i][j] << " ";
		std::cout << std::endl;
	}
}
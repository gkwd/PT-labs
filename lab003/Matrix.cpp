#include "../headers.h"
#include "Matrix.h"

Matrix::Matrix(int _cols, int _rows)
{
	id = ++counter;
	this->x_rows = _rows;
	this->y_columns = _cols;
	this->matrix = new int* [y_columns];

	for (size_t i = 0; i < this->y_columns; i++)
	{
		this->matrix[i] = new int[this->x_rows];
	}
}

Matrix::Matrix(Matrix &mx) : y_columns(mx.y_columns), x_rows(mx.x_rows)
{
	id = ++counter;
	this->matrix = new int* [this->y_columns];

	for (size_t i = 0; i < this->y_columns; i++)
	{
		this->matrix[i] = new int[this->x_rows];
	}
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < this->y_columns; i++)
	{
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
}

void Matrix::info()
{
	std::cout << "Row size: " << this->x_rows << std::endl;
	std::cout << "Column size: " << this->y_columns << std::endl;
	std::cout << "Id matrix: " << this->id<< std::endl;
	std::cout << "Total count: " << this->counter << std::endl;
	std::cout << "============= Matrix =============" << std::endl;

	for (size_t i = 0; i < this->y_columns; i++)
	{
		for (size_t j = 0; j < this->x_rows; j++)
		{
			std::cout << this->matrix[i][j];
		}
		std::cout << std::endl;
	}
	
	std::cout << "============= Matrix =============" << std::endl;
}
int Matrix::counter = 0;
#include "../headers.h"
#include "lab003.h"


namespace ui_labs {
	namespace lab003 {
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

		Matrix::Matrix(const Matrix& mx) : y_columns(mx.y_columns), x_rows(mx.x_rows)
		{
			id = ++counter;
			this->matrix = new int* [this->y_columns];

			for (size_t i = 0; i < this->y_columns; i++)
			{
				this->matrix[i] = new int[this->x_rows];
			}

			for (size_t i = 0; i < this->y_columns; i++)
			{
				for (size_t j = 0; j < this->x_rows; j++)
				{
					this->matrix[i][j] = mx.matrix[i][j];
				}
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
			std::cout << "\n\n\nRow size: " << this->x_rows << std::endl;
			std::cout << "Column size: " << this->y_columns << std::endl;
			std::cout << "Id matrix: " << this->id << std::endl;
			std::cout << "Total count: " << this->counter << std::endl;
			std::cout << "============= Matrix " << this->id <<  " =============" << std::endl;

			for (size_t i = 0; i < this->y_columns; i++)
			{
				for (size_t j = 0; j < this->x_rows; j++)
				{
					std::cout << this->matrix[i][j] << " | ";
				}
				std::cout << std::endl;
			}

			std::cout << "============= Matrix " << this->id << " =============" << std::endl;
		}


		Matrix Matrix::operator+(const Matrix& mx)
		{
			Matrix temp((*this));
			if (temp.x_rows != mx.x_rows || temp.y_columns != mx.y_columns)
			{
				std::cerr << "Matrix must be equal!";
				throw CustomExeption("Matrix must be equal!", -3);
			}
			for (size_t i = 0; i < mx.y_columns; i++) {
				for (size_t j = 0; j < mx.x_rows; j++) {
					temp.matrix[i][j] += mx.matrix[i][j];
				}
			}
			return temp;

		}
		Matrix Matrix::operator-(const Matrix& mx)
		{
			Matrix temp((*this));
			if (temp.x_rows != mx.x_rows || temp.y_columns != mx.y_columns)
			{
				std::cerr << "Matrix must be equal!";
				throw CustomExeption("Matrix must be equal!", -3);
			}
			for (size_t i = 0; i < mx.y_columns; i++) {
				for (size_t j = 0; j < mx.x_rows; j++) {
					temp.matrix[i][j] -= mx.matrix[i][j];
				}
			}
			return temp;

		}
		Matrix Matrix::operator*(const Matrix& mx)
		{
			Matrix temp(this->y_columns, mx.x_rows);
			if (mx.y_columns != temp.x_rows)
			{
				std::cerr << "Matrix 1 colums must be equal to Matrix 2 rows!";
				throw CustomExeption("Matrix 1 colums must be equal to Matrix 2 rows!", -4);
			}
			for (size_t i = 0; i < mx.x_rows; i++)
			{
				for (size_t j = 0; j < this->y_columns; j++)
				{
					temp.matrix[i][j] = this->matrix[i][j] * mx.matrix[i][j];
				}
			}

			return temp;
		}
		Matrix operator*(const Matrix& mx1, const int number)
		{
			Matrix temp (mx1.y_columns, mx1.x_rows);
			for (int i = 0; i < mx1.y_columns; i++) {
				for (int j = 0; j < mx1.x_rows; j++) {
					temp.matrix[i][j] = number * mx1.matrix[i][j];
				}		
			}
			return temp;
		}
		int Matrix::counter = 0;
	}
}
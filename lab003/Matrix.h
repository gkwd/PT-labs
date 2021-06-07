#ifndef LAB003_MATRIX
#define LAB003_MATRIX

//include Vector
#include "../lab002/lab002.h"

class Matrix
{
	public:
		Matrix(int _cols, int _rows);
		Matrix(Matrix &mx);
		~Matrix();

		static int counter;
		void info();
		friend Matrix operator+(const Matrix& mx1, const Matrix& mx2);
		friend Matrix operator-(const Matrix& mx1, const Matrix& mx2);
		friend Matrix operator-(const Matrix& mx1);

		friend Matrix operator*(const Matrix& mx1, const Matrix& mx2);
		friend Matrix operator*(const Matrix& mx1, const Vector& v1);
		friend Matrix operator*(const Matrix& mx1, const int& number);

		Matrix& operator=(const Matrix& mx_right) {
			if (this == &mx_right)
			{
				return *this;
			}
			this->x_rows = mx_right.x_rows;
			this->y_columns = mx_right.y_columns;
			this->matrix = mx_right.matrix;
			id = ++counter;
		}
	
	private:
		int x_rows;
		int y_columns;
		int** matrix;
		int id;
};


#endif LAB003_MATRIX

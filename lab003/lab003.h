#ifndef LAB003_MATRIX
#define LAB003_MATRIX

//include Vector
#include "../lab002/lab002.h"

namespace ui_labs {
	namespace lab003 {

		class Matrix
		{
		public:
			Matrix(int _cols, int _rows);
			Matrix(const Matrix& mx);
			~Matrix();

			static int counter;
			int** matrix;

			void info();
			Matrix operator+(const Matrix&);
			Matrix operator-(const Matrix&);

			Matrix operator*(const Matrix&);
			friend Matrix operator*(const Matrix& mx1, const int number);

			// TODO: Implement inverse matrix
			friend Matrix operator-(const Matrix& mx1);
			// TODO: Implement this method 
			friend Matrix operator*(const Matrix& mx1, const Vector& v1);


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
			int id;
		};
	}
}
#endif LAB003_MATRIX

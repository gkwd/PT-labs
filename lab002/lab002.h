#ifndef LAB002_VECTOR
#define LAB002_VECTOR
#include "../helpers/helpers.h"

class Vector
{
public:
	Vector();
	Vector(Point2d f, Point2d s);
	Vector(const Vector &vct);
	~Vector();
	int info();
	static int size;

	friend Point2d operator+(const Vector &v1, const Vector &v2);
	friend Point2d operator-(const Vector& v1, const Vector& v2);

	// ��������� ������������� ���� ��������  �  ���������� �����, 
	// ������ ������������ ���� ���� �������� �� ������� ���� ����� ���� v_A * v_B * cos(v_A;v_B)
	friend double operator*(const Vector& v1, const Vector& v2);
	friend Vector operator-(Vector &v1);

	// ����� ������� � ������� ������������ |l_A| = sqrt(x*x + y*y)
	int get_length();
	// ���������� ������� {x2 - x1; y2 - y1}
	Point2d get_coords();
	


private:
	int id;
	int length;
	Point2d coords_f;
	Point2d coords_s;
	Point2d coords;
};


#endif LAB002_VECTOR

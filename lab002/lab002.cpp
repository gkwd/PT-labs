#include "../headers.h"
#include "lab002.h"



int Vector::size = 0;

Vector::Vector() : coords_f({0,0}), coords_s({ 0,0 })
{
	coords = { coords_s.x - coords_f.x, coords_s.y - coords_f.y };
	length = sqrt(pow(coords.x, 2) + pow(coords.y, 2));
	size++;
	id = size;
}

Vector::Vector(Point2d f, Point2d s) : coords_f(f), coords_s(s)
{
	coords = { coords_s.x - coords_f.x, coords_s.y - coords_f.y };
	length = sqrt(pow(coords.x, 2) + pow(coords.y, 2));
	size++;
	id = size;
}

Vector::Vector(const Vector &vct) : 
	coords(vct.coords), length(vct.length), coords_f(vct.coords_f), coords_s(coords_f)
{
	size++;
	id = size;
}

Vector::~Vector()
{
	size--;
}

int Vector::info()
{
	std::cout << "V length: " << length << std::endl;
	std::cout << "V coordinates: x = " << coords.x << " y = " << coords.y << std::endl;
	std::cout << "V number: " << id << std::endl;

	return 0;
}

int Vector::get_length()
{
	return length;
}


Point2d Vector::get_coords() {
	return coords;
}

Point2d operator+(const Vector& v1, const Vector& v2)
{

	return Point2d{ v1.coords.x + v2.coords.x, v1.coords.y + v2.coords.y };
}

Point2d operator-(const Vector& v1, const Vector& v2)
{
	return Point2d{ v1.coords.x - v2.coords.x, v1.coords.y - v2.coords.y };
}

double operator*(const Vector& v1, const Vector& v2)
{
	auto l1 = v1.length;
	auto l2 = v2.length;
	auto cosAngle = (v1.coords.x * v2.coords.x + v1.coords.y * v2.coords.y) / (l1 * l2);

	return l1 * l2 * cosAngle;
}

Vector operator-(Vector &v1)
{
	v1.coords = { v1.coords.x + -1, v1.coords.y * -1 };
	return v1;
}

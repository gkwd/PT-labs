#include "../headers.h"

#ifndef HELPERS
#define HELPERS

bool is_string(std::string str);

struct Item
{
	short id;
	std::string name;
	int price;
};

struct Product
{
	int id;
	std::string name;
	Product* next;
};

struct Point2d {
	int x;
	int y;
};

struct Point3d {
	int x;
	int y;
	int z;
};


Item create_item(short id);
Product create_product(short id);

#endif HELPERS

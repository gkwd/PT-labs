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


class CustomExeption
{
public:
	CustomExeption(std::string msg, short code);
	CustomExeption(std::string msg);
	CustomExeption();

	~CustomExeption();

	std::string error_message = "Unknown exeption";
	short error_code = 1;
	bool is_code_provided = false;
};

#endif HELPERS

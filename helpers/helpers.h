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


Item create_item(short id);

#endif HELPERS

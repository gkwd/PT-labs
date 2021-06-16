#include "../headers.h"
#include "lab001_linked.h"
#include "../helpers/helpers.h"
// TODO: Finish this
void Linked::del_at(short id)
{
}

void Linked::push_front(Product item)
{
}

void Linked::push(Product item)
{
}

Linked::Linked() : length(0), lastIndex(-1)
{
	std::string answer;
	
	while (answer != "n" || answer != "y" || answer != "no" || answer != "yes")
	{
		std::cout << "Do you want to create list? [y/n]";
		std::cin >> answer;
	}
	if (answer == "yes" || answer == "y") {
		Product item = create_product(lastIndex + 1);
		item.next = last;
		first = &item;
	}
}

Linked::~Linked()
{
	Product *item = first;
	while (length != 0)
	{
		if (first->next != nullptr) {
			Product* next = first->next->next;
		}
		Product *temp_item = item;
		item = item->next;

		delete item;
		length--;
	}
}
#include "../headers.h"
#include "../helpers/helpers.h"

#ifndef LAB001
#define LAB001

class ItemList
{
	public:
		ItemList();
		ItemList(int l);
		void add(Item item, int index);
		void push(Item item);
		void push_front(Item item);
		void pop();
		void pop_front();
		void del_at(short id);
		int size();
		Item at(int pos);
		void display_list();
		int find_item();
		~ItemList();
		

	private:
		int length;
		int lastIndex;
		struct Item* itemArray = nullptr;
};

#endif LAB001


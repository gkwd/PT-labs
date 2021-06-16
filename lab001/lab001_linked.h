#include "../helpers/helpers.h"
#ifndef LINKED
#define LINKED

class Linked
{
	public:
		Product* first = nullptr;
		Product* last = nullptr;
		int length;
		int lastIndex;

		void add(short id);
		void del_at(short id);
		void push_front(Product item);
		void push(Product item);



		Linked();
		~Linked();

	private:

};

#endif LINKED


#include "../headers.h"
#include "lab001_ptr.h"

ItemList::ItemList() : itemArray(nullptr), length(0), lastIndex(0)
{
	
}

ItemList::ItemList(int l) : itemArray(new Item[l]), length(l), lastIndex(l - 1)
{

}

ItemList::~ItemList()
{
	delete[] itemArray;
}

void ItemList::pop() {
	if (itemArray == nullptr || length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	struct Item* newArray;
	length = length - 1;
	lastIndex = length - 1;
	newArray = new Item[length];

	for (int i = 0; i < length; i++) {
		newArray[i] = itemArray[i];
	}
	delete[] itemArray;
	itemArray = newArray;
	std::cout << "Element removed from end" << std::endl;

	return;
}
void ItemList::pop_front() {
	if (itemArray == nullptr || length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	struct Item* newArray;
	length = length - 1;
	lastIndex = length - 1;
	newArray = new Item[length];

	for (int i = 1, nI = 0; i < length; i++, nI++) {
		newArray[nI] = itemArray[i];
	}

	delete[] itemArray;
	itemArray = newArray;
	std::cout << "Element removed from begining" << std::endl;
	return;
}


void ItemList::push(Item item)
{
	struct Item* newArray;
	length = length + 1;
	lastIndex = length - 1;
	newArray = new Item[length];

	for (int i = 0; i < length; i++) {
		if (i == lastIndex)
		{
			newArray[i] = item;
		}
		else {
			newArray[i] = itemArray[i];
		}
	}
	delete[] itemArray;
	itemArray = newArray;
	std::cout << "Element inserted to  end" << std::endl;
	return;
}


void ItemList::push_front(Item item) {
	struct Item* newArray;
	length = length + 1;
	lastIndex = length - 1;
	newArray = new Item[length];

	for (int i = 0; i < length; i++) {
		if (i == 0)
		{
			newArray[i] = item;
		}
		else {
			newArray[i] = itemArray[i - 1];
		}
	}
	delete[] itemArray;
	itemArray = newArray;
	std::cout << "Element added to begging" << std::endl;

	return;
}

int ItemList::size() {
	if (itemArray == nullptr || length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return 0;
	}
	return length;
}

Item ItemList::at(int pos) {
	if (itemArray == nullptr || length == 0)
	{
		std::cout << "List is empty" << std::endl;
		const Item item = create_item(length);
		return item;
	}
	if (pos > length || pos < 0)
	{
		std::cerr << "Error position out of range";
		return {};
	}
	return itemArray[pos];
}

void ItemList::display_list() {
	if (itemArray == nullptr || length == 0)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "================================" << std::endl;
		std::cout << "Item id: " << itemArray[i].id << std::endl;
		std::cout << "Item name: " << itemArray[i].name << std::endl;
		std::cout << "Item price: " << itemArray[i].price << std::endl;
	}
}

void ItemList::add(Item item, int index) {
	if (lastIndex < index)
	{
		push(item);
		return;
	}
	struct Item* firstArray = new Item[index];
	struct Item* secondArray = new Item[length - index];
	

	for (size_t i = 0; i < index; i++)
	{
		firstArray[i] = itemArray[i];
	}

	for (size_t j = index, l = 0; j < length; j++, l++)
	{
		secondArray[l] = itemArray[j];
	}

	length += 1;
	struct Item* newArray = new Item[length];

	for (size_t k = 0, c = 0; k < length; k++)
	{ 
		if (k < index)
		{
			newArray[k] = firstArray[k];
		} 
		else if (k > index)
		{
			newArray[k] = firstArray[c];
			c++;
		}
		else if (k == index)
		{
			newArray[k] = item;
		}
	}
}


void ItemList::del_at(short id) {
	struct Item* newArray = new Item[length - 1];
	size_t i = 0;
	size_t o = 0;
	while (i < length)
	{
		if (i != id) {
			newArray[o] = itemArray[i];
			o++;
		}
		i++;
	}
	length -= 1;
	delete[] itemArray;
	itemArray = newArray;

	return;
}

int deleteElement(int arr[], int n, int x)
{
	// Search x in array
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			break;

	// If x found in array
	if (i < n)
	{
		// reduce size of array and move all
		// elements on space ahead
		n = n - 1;
		for (int j = i; j < n; j++)
			arr[j] = arr[j + 1];
	}

	return n;
}


int ItemList::find_item() {
		int list_item_id = -1;
		std::string temp_id;
		std::string list_item_name = "";
		display_list();
		std::cout << "Выберите элемент из списка (желательно из имени или номера)" << std::endl;
		std::cin >> temp_id;

		if (!is_string(temp_id))
		{
			for (size_t i = 0; i < length; i++)
			{
				const Item it = at(i);
				if (temp_id == it.name)
				{
					list_item_id = i;
					return list_item_id;
				}
			}

			if (list_item_id == -1)
			{
				std::cout << "Подукт не найден в вашем списке! Проверьте правильность написания или добавите новый предмет." << std::endl;
				return 0;
			}
		}
		else {
			list_item_id = stoi(temp_id);
			if (list_item_id > lastIndex || list_item_id < 0)
			{
				std::cout << "Ошибка номер не может быть вне диапазона" << std::endl;
				return -1;
			}
			for (size_t i = 0; i < length; i++)
			{
				const Item it = at(i);
				if (list_item_id == it.id)
				{
					list_item_id = i;
					return list_item_id;
				}
			}
			return list_item_id;
		}
}
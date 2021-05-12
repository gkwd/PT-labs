#include <iostream>
#include <vector>

using namespace std;

struct product {
	string name;
	float price;
	int amount;
	//указатель на следующий по порядку элемент
	product* next;
};


// Добавляет элемент в начало списка
// Создает первую запись о товаре, если список пустой
int addfirst(vector<product>* list, product item) {
	(*list).insert((*list).begin(), item);
}


// Выводит на экран всю информацию о каждом элементе
void printlist(vector<product>* list) {
	for (size_t i = 0; i != (*list).size(); i++)
	{
		const product it = (*list).at(i);
		cout << "Название продукта: " << it.name << endl;
		cout << "Цена продукта: " << it.price << endl;
		cout << "Кол-во продукта: " << it.amount << endl;
	}
}

// Выводит на экран всю информацию об одном выбранном элементе
int printitem(product item) {
	cout << "Название продукта: " << item.name << endl;
	cout << "Цена продукта: " << item.price << endl;
	cout << "Кол-во продукта: " << item.amount << endl;

}

// Добавляет новый элемент в конец списка
int addlast(vector<product>* list, product item) {
	(*list).push_back(item);
}

// Вставляет новый элемент сразу после выбранного элемента
int addafter(int itemId, product item, vector<product>* list) {
	(*list).insert((*list).begin() + itemId, item);
}

// Вставляет новый элемент перед выбранным элементом
int addbefore(int itemId, product item, vector<product>* list) {
	(*list).insert((*list).begin() - itemId, item);
}


// Удаляет выбранный элемент из списка
int del(int itemId, vector<product>* list) {

}


int main() {
	product* bufet = NULL;
	int res, k, amount;
	string name, nameafter;
	float price;

	k = -1;

	while (k != 0) {
		while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7) {
			cout << "To add an item at the end of the list, enter 1;\n\
            to add an item to the top of the list, enter 2;\n\
            to delete an item, enter 3; \n\
            to add after an item, enter 4;\n\
            to add befor an item, enter 5;\n\
            to find an item, enter 6;\n\
            to print a list, enter 7;\n\
            to exit, enter 0: ";
			cin >> k;
			cout << "\n\n";

			if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7) {
				cout << "Wrong code!\n\n";
				system("pause");
			}
			else {
				switch (k) {
				case 0: {
					//Выходим из цикла
					break;
				}
				case 1: {
					// Реализуем логику добавления элемента в конец списка
					k = 100;
					break;
				}
				case 2: {
					// Реализуем логику добавления элемента в начало списка
					k = 100;
					break;
				}

				case 3: {
					// Реализуем логику удаления элемента из списка
					k = 100;
					break;
				}
				case 4: {
					// Просим пользователя выбрать элемент (например, ввести название)

					// Реализуем логику добавления нового элемента в список сразу ПОСЛЕ выбранного элемента
					k = 100;
					break;
				}
				case 5: {
					// Просим пользователя выбрать элемент (например, ввести название)

					// Реализуем логику добавления нового элемента в список сразу ПЕРЕД выбранным элементом
					k = 100;
					break;
				}
				case 6: {
					// Просим пользователя выбрать элемент (например, ввести название)

					// Выводим на экран информацию о выбранном элементе
					k = 100;
					break;
				}
				case 7: {
					// Выводим на экран информацию о всех элементах списка
					k = 100;
					break;
				}
				}
			}
			cout << "\n\n";
		}
	}

	return 0;
}
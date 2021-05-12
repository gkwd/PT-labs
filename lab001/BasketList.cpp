#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct product {
	string name;
	float price;
	int amount;
};


bool is_string(string str) {
	if (isdigit(str[0]) == false) {
		return false;
	}
	return true;
}

bool list_checker(int id, vector<product>* list) {
	return ((*list).size() < id || id < 0);
}



// Добавляет элемент в начало списка
// Создает первую запись о товаре, если список пустой
void add_first(vector<product>* list, product item) {
	(*list).insert((*list).begin(), item);
}


// Выводит на экран всю информацию о каждом элементе
void print_list(vector<product>* list) {
	for (size_t i = 0; i != (*list).size(); i++)
	{
		const product it = (*list).at(i);
		cout << "Номер продукта: " << i + 1 << endl;
		cout << "Название продукта: " << it.name << endl;
		cout << "Цена продукта: " << it.price << endl;
		cout << "Кол-во продукта: " << it.amount << endl;
		cout << endl;
	}
}

// Выводит на экран всю информацию об одном выбранном элементе
void print_item(product item) {
	cout << "Название продукта: " << item.name << endl;
	cout << "Цена продукта: " << item.price << endl;
	cout << "Кол-во продукта: " << item.amount << endl;

}

// Добавляет новый элемент в конец списка
void add_last(vector<product>* list, product item) {
	(*list).push_back(item);
}

// Вставляет новый элемент сразу после выбранного элемента
void add_after(int itemId, product item, vector<product>* list) {
	if (list_checker(itemId, &(*list)))
	{
		cout << "Номер не может быть больше длины списка ил меньше нуля" << endl;
		add_last(&(*list), item);
		return;
	}
	(*list).insert((*list).begin() + itemId, item);
}

// Вставляет новый элемент перед выбранным элементом
void add_before(int itemId, product item, vector<product>* list) {
	if (list_checker(itemId, &(*list)))
	{
		cout << "Номер не может быть больше длины списка ил меньше нуля" << endl;
		add_first(&(*list), item);
		return;
	}
	(*list).insert((*list).begin() + (itemId - 1), item);
}


// Удаляет выбранный элемент из списка
void del(int itemId, vector<product>* list) {
	if (list_checker(itemId, &(*list)))
	{
		cout << "Ошибка номер не может быть больше длины списка" << endl;
		return;
	}
	(*list).erase((*list).begin() + itemId - 1);
}

int fint_item(vector<product>* list) {
	int list_item_id = -1;
	string temp_id;
	string list_item_name = "";
	print_list(&(*list));
	cout << "Выберите элемент из списка (желательно из имени или номера)" << endl;
	cin >> temp_id;

	if (!is_string(temp_id))
	{
		for (size_t i = 0; i < (*list).size(); i++)
		{
			const product it = (*list).at(i);
			if (temp_id == it.name)
			{
				list_item_id = i;
				return list_item_id;
			}
		}

		if (list_item_id == -1)
		{
			cout << "Подукт не найден в вашем списке! Проверьте правильность написания или добавите новый предмет." << endl;
			return 0;
		}
	}
	else {
		list_item_id = stoi(temp_id);
		if (list_checker(list_item_id, &(*list)))
		{
			cout << "Ошибка номер не может быть больше длины списка" << endl;
			return 0;
		}
		return list_item_id;
	}
}


product create_product() {
	product newPrd;
	cout << "Введите название: ";
	cin >> newPrd.name;
	cout << "Введите кол-во: ";
	cin >> newPrd.amount;
	cout << "Введите цену: ";
	cin >> newPrd.price;
	cout << endl;

	return newPrd;
}

int main() {
	setlocale(LC_ALL, "Russian");
	product* bufet = NULL;
	int res, k, amount;
	string name, nameafter;
	float price;

	vector<product> list{};

	k = -1;

	while (k != 0) {
		while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7) {
			cout << "To add an item at the end of the list, enter 1; \n"
				 << "to add an item to the top of the list, enter 2;\n"
				 << "to delete an item, enter 3; \n"
				 << "to add after an item, enter 4;\n"
				 << "to add befor an item, enter 5;\n"
				 << "to find an item, enter 6;\n"
				 << "to print a list, enter 7;\n"
				 <<	"to exit, enter 0: \n ";
			cin >> k;
			cout << "\n\n";

			if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7) {
				cout << "Wrong code!\n\n";
				system("pause");
			}
			else {
				switch (k) {
				case 0: {
					cout << "Спасибо что пользовались нашей программой ;)" << endl;
					break;
				}
				case 1: {
					// Реализуем логику добавления элемента в конец списка
					const product prd = create_product();
					add_last(&list, prd);
					k = -1;
					break;
				}
				case 2: {
					// Реализуем логику добавления элемента в начало списка
					const product prd = create_product();
					add_first(&list, prd);
					k = -1;
					break;
				}

				case 3: {
					// Реализуем логику удаления элемента из списка
					int itemId = -1;
					cout << "Введите номер элемента котрый вы хотите удалить";
					cin >> itemId;
					if (itemId < 0 || list.size() == 0 || itemId > list.size())
					{
						cout << "Undefined Argument Exeption" << endl;
						k = -1;
						break;
					}
					del(itemId, &list);
					k = -1;
					break;
				}
				case 4: {
					// Просим пользователя выбрать элемент (например, ввести название)
					int item_id = fint_item(&list);

					const product prd = create_product();
					add_after(item_id, prd, &list);
					// Реализуем логику добавления нового элемента в список сразу ПОСЛЕ выбранного элемента
					k = -1;
					break;
				}
				case 5: {
					// Просим пользователя выбрать элемент (например, ввести название)
					int item_id = fint_item(&list);

					const product prd = create_product();
					add_before(item_id, prd, &list);
					// Реализуем логику добавления нового элемента в список сразу ПЕРЕД выбранным элементом
					k = -1;
					break;
				}
				case 6: {
					// Просим пользователя выбрать элемент (например, ввести название)
					int item_id = fint_item(&list);
					print_item(list.at(item_id));
					// Выводим на экран информацию о выбранном элементе
					k = -1;
					break;
				}
				case 7: {
					// Выводим на экран информацию о всех элементах списка
					if (list.empty())
					{
						cout << "Список пуст" << endl;
						k = -1;
						break;
					}
					print_list(&list);
					k = -1;
					break;
				}
				}
			}
			cout << "\n\n";
		}
	}

	return 0;
}
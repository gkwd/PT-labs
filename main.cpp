#include "headers.h"
#include "lab001/lab001_ptr.h"

int main()
{
    setlocale(LC_ALL, "rus");

    ItemList list;
    int res, k, amount;
    std::string name, nameafter;
    float price;

    k = -1;

    while (k != 0) {
        while (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7) {
            std::cout 
            << "To add an item at the end of the list, enter 1;\n"
            << "to add an item to the top of the list, enter 2;\n"
            << "to delete an item, enter 3; \n"
            << "to add after an item, enter 4;\n"
            << "to add befor an item, enter 5;\n"
            << "to find an item, enter 6;\n"
            << "to print a list, enter 7;\n"
            << "to exit, enter 0: ";                                        
            std::cin >> k;
            std::cout << "\n\n";

            if (k != 0 && k != 1 && k != 2 && k != 3 && k != 4 && k != 5 && k != 6 && k != 7) {
                std::cout << "Wrong code!\n\n";
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
                    const Item prd = create_item(list.size());
                    list.push(prd);
                    k = -1;
                    break;
                }
                case 2: {
                    // Реализуем логику добавления элемента в начало списка
                    const Item prd = create_item(list.size());
                    list.push_front(prd);
                    k = -1;
                    break;
                }

                case 3: {
                    // Реализуем логику удаления элемента из списка
                    const short id = list.find_item();

                    list.del_at(id);
                    k = -1;
                    break;
                }
                case 4: {
                    // Просим пользователя выбрать элемент (например, ввести название)
                    const int id = list.find_item();
                    const Item prd = create_item(list.size());
                    list.add(prd, id);
                    // Реализуем логику добавления нового элемента в список сразу ПОСЛЕ выбранного элемента
                    k = -1;
                    break;
                }
                case 5: {
                    // Просим пользователя выбрать элемент (например, ввести название)
                    const int id = list.find_item();
                    const Item prd = create_item(list.size());
                    list.add(prd, id + 1);
                    // Реализуем логику добавления нового элемента в список сразу ПЕРЕД выбранным элементом
                    k = -1;
                    break;
                }
                case 6: {
                    // Просим пользователя выбрать элемент (например, ввести название)
                    const int id = list.find_item();
                    Item item = list.at(id);
                    std::cout << "Item id: " << item.id << std::endl;
                    std::cout << "Item name: " << item.name << std::endl;
                    std::cout << "Item price: " << item.price << std::endl;
                    // Выводим на экран информацию о выбранном элементе
                    k = -1;
                    break;
                }
                case 7: {
                    // Выводим на экран информацию о всех элементах списка
                    list.display_list();
                    k = -1;
                    break;
                }
                }
            }
            std::cout << "\n\n";
        }
    }

    return 0;
}

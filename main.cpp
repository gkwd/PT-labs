#include "headers.h"
#include "lab001/lab001_ptr.h"
#include "lab002/lab002.h"
#include "lab003/lab003.h"


/*
* 
* Добрый день! Проект сделан с учетом моего опыта в оптимизации сборки
* На туисе разрешено загружать только .срр файлы поэтому вы видите здесь этот блок окмментариев.
* Вся работа доступна в репозитории на GitHub.
* 
*/

void init_lab001() {

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
}

void init_lab002() {
    Point2d v1_xy1{ 2, 3 };
    Point2d v1_xy2{ 5, 7 };
    Point2d v2_xy1{ 8, 9 };
    Point2d v2_xy2{ 1, 1 };

    Vector v1{ v1_xy1, v1_xy2 };
    Vector v2{ v2_xy1, v2_xy2 };

    short task_id = -1;
    std::cout << "Vector #1 ============================ " << std::endl;
    v1.info();
    std::cout << "Vector #2 ============================ " << std::endl;
    v2.info();

    std::cout << "Sum of vectors: x = " << (v1 + v2).x << " y = " << (v1 + v2).y << std::endl;
    std::cout << "Multiplication of vectors: " << v1 * v2 << std::endl;
    std::cout << "Unary minus of vector 1: " << std::endl;
    (-v1).info();

    Vector copied{ v2 };

    std::cout << "Copied vector info ===================: " << std::endl;
    copied.info();
}



void init_lab003() {
    const short DEFAULT_ROW_SIZE = 3;
    const short DEFAULT_COLUMN_SIZE = 3;
    using namespace ui_labs::lab003;

    Matrix first(DEFAULT_COLUMN_SIZE, DEFAULT_ROW_SIZE);
    for (size_t i = 0; i < DEFAULT_COLUMN_SIZE; i++)
    {
        for (size_t j = 0; j < DEFAULT_ROW_SIZE; j++)
        {
            first.matrix[i][j] = 3;
        }
    }
    first.info();

    Matrix second(DEFAULT_COLUMN_SIZE, DEFAULT_ROW_SIZE);
    for (size_t i = 0; i < DEFAULT_COLUMN_SIZE; i++)
    {
        for (size_t j = 0; j < DEFAULT_ROW_SIZE; j++)
        {
            second.matrix[i][j] = 3;
        }
    }
    second.info();

    Matrix third(DEFAULT_COLUMN_SIZE, DEFAULT_ROW_SIZE);
    for (size_t i = 0; i < DEFAULT_COLUMN_SIZE; i++)
    {
        for (size_t j = 0; j < DEFAULT_ROW_SIZE; j++)
        {
            third.matrix[i][j] = 3;
        }
    }
    third.info();

    std::cout << "Operator + (Addition) Matrix + Matrix" << std::endl;
    Matrix plus = first + second;
    plus.info();

    std::cout << "Operator + (Multiplication) Matrix * Matrix" << std::endl;
    Matrix multiplication = first * second;
    multiplication.info();


    std::cout << "Operator * (Multiplication) Matrix * Number" << std::endl;
    Matrix multiplicationNumber = first * 5;
    multiplicationNumber.info();


    std::cout << "Copied matrix (multiplicationNumber)" << std::endl;
    Matrix copied(multiplicationNumber);
    copied.info();

    std::cout << "Matrix assignment = (Multiplication)" << std::endl;
    Matrix assigment = multiplication;
    assigment.info();
}


int main()
{
    setlocale(LC_ALL, "rus");

    short lab_id = -1;

    while (lab_id != 0)
    {
        
        while (!(lab_id == 1 || lab_id == 2 || lab_id == 3))
        {
            std::cout << "Choose lab: ";
            
            std::cin >> lab_id;
            if (!(lab_id == 1 || lab_id == 2 || lab_id == 3))
            {
                std::cout << "Wrong code" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                system("pause");
            }
            else {
                switch (lab_id)
                {
                case 0: {
                    break;
                }
                case 1: {
                    init_lab001();
                    break;
                }
                case 2: {
                    init_lab002();
                    break;
                }
                case 3: {
                    init_lab003();
                    break;
                }
                default:
                    std::cout << "Something went wrong" << std::endl;
                    break;
                }
            }
            
        }
    }
    
    return 0;
}

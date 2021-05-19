#include "../headers.h"

bool is_string(std::string str) {
	if (isdigit(str[0]) == false) {
		return false;
	}
	return true;
}


Item create_item(short id) {
    using namespace std;
    Item newPrd;
    newPrd.id = id;
    cout << "Item name: ";
    cin >> newPrd.name;
    cout << "Item price: ";
    cin >> newPrd.price;
    cout << endl;

    return newPrd;
}
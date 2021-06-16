#include "../headers.h"
#include "helpers.h"

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


Product create_product(short id) {
    using namespace std;
    Product newPrd;
    newPrd.id = id;
    cout << "Item name: ";
    cin >> newPrd.name;
    cout << endl;

    return newPrd;
}

CustomExeption::CustomExeption(std::string msg, short code) {
    error_message = msg;
    is_code_provided = true;
    error_code = code;
}
CustomExeption::CustomExeption(std::string msg) {
    error_message = msg;
    is_code_provided = false;
}
CustomExeption::CustomExeption() {}

CustomExeption::~CustomExeption() {

}

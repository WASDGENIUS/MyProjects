#include <iostream>
#include <cmath>
#include <string>


void array() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::string str = "Hello, World!";
    std::cout << str << std::endl;
    for (size_t i = 0; i < str.length(); i++) {
        std::cout << str[i] << " ";
    }
}

int main() {
    array();
    return 0;
}
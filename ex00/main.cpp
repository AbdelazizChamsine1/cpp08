#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);
        lst.push_back(35);
        lst.push_back(45);

        std::cout << "Searching in vector:" << std::endl;
        std::vector<int>::iterator vit = easyfind(vec, 30);
        std::cout << "Found: " << *vit << std::endl;

        std::cout << "Searching in list:" << std::endl;
        std::list<int>::iterator lit = easyfind(lst, 25);
        std::cout << "Found: " << *lit << std::endl;

        std::cout << "Searching for missing value:" << std::endl;
        easyfind(vec, 99); // Will throw
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

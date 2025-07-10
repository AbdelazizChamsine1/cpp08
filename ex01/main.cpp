#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Extra test: 10,000 random numbers
    try {
        Span bigSpan(10000);
        std::srand(std::time(0));
        std::vector<int> nums;
        for (int i = 0; i < 10000; ++i)
            nums.push_back(std::rand());

        bigSpan.addNumber(nums.begin(), nums.end());

        std::cout << "Big Span - Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Span - Longest: " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Big Span Error: " << e.what() << std::endl;
    }

    return 0;
}

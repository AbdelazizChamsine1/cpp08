#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _data = other._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_data.size() >= _maxSize)
        throw std::runtime_error("Span is already full");
    _data.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (_data.size() + std::distance(begin, end) > _maxSize)
        throw std::runtime_error("Not enough space in Span for the range");
    _data.insert(_data.end(), begin, end);
}

int Span::shortestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements for a span");

    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_data.size() < 2)
        throw std::runtime_error("Not enough elements for a span");

    int min = *std::min_element(_data.begin(), _data.end());
    int max = *std::max_element(_data.begin(), _data.end());
    return max - min;
}

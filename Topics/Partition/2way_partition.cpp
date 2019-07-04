#include <algorithm>
#include <iostream>
#include <vector>

// #define SINGLE_DIRECT
#define OPPOSITE_DIRECT

using Type = int;

void
TwoWayPartition(std::vector<Type>& array) {
#ifdef SINGLE_DIRECT
    Type pivot = array[0];
    size_t left = 0;
    for (size_t right = 1; right < array.size(); right++) {
        if (array[right] < pivot) {
            std::swap(array[++left], array[right]);
        }
    }
    std::swap(array[0], array[left]);
#elif defined OPPOSITE_DIRECT
    Type pivot = array[0];
    size_t left = 0;
    size_t right = array.size();
    while (true) {
        while (left < array.size() - 1 && array[++left] < pivot) {
            ;
        }
        while (right >= 1 && array[--right] > pivot) {
            ;
        }
        if (left < right) {
            std::swap(array[left], array[right]);
        } else {
            break;
        }
    }
    std::swap(array[right], array[0]);
#endif
}

int
main(void) {
    std::vector<Type> array = { 40, 9, 5, 9, 23, 54, 89, 9, 18 };
    TwoWayPartition(array);
    for (auto i : array) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

#define UNIDIRECTIONAL

using Type = int;

void
TwoWayPartition(std::vector<Type>& array) {
#ifdef UNIDIRECTIONAL
    Type pivot = array[0];
    size_t left = 0;
    for (size_t right = 1; right < array.size(); right++) {
        if (array[right] < pivot) {
            std::swap(array[++left], array[right]);
        }
    }
    std::swap(array[0], array[left]);
#endif
}

int
main(void) {
    std::vector<Type> array = { 9, 5, 9, 23, 54, 89, 9, 18 };
    TwoWayPartition(array);
    for (auto i : array) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

std::pair<int, int>
Partition(std::vector<int>& array, int pivot) {
    int i = 0;
    int j = 0;
    int k = array.size() - 1;
    while (j <= k) {
        if (array[j] < pivot) {
            std::swap(array[i], array[j]);
            i++;
            j++;
        } else if (array[j] == pivot) {
            j++;
        } else {
            std::swap(array[j], array[k]);
            k--;
        }
    }
    return { i, j };
}

int
main(void) {
    std::vector<int> array = { 27, 27, 5, 6, 3,   8,  5, 6,
                               4,  3,  3, 6, 443, 54, 0, 6 };
    std::pair<int, int> result = Partition(array, 5);
    for (auto i : array) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout << "Result: [" << result.first << ", " << result.second << ")"
              << std::endl;
    return 0;
}
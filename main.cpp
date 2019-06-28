#include <iostream>
#include "algorithm.h"


int main() {

    int array[] = {2, 7, 4, 4, 1, 3, 8, 7, 10, 3};

    algorithm::sort::BubbleSort(array, 10);

    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;


    return 0;
}
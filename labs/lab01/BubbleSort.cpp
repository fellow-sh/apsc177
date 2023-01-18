#include <iostream>

int size;

// initial bubble sort algorithm in lab
int bubbleSort() {
    int list[size]; // initialize array
    bool swap;
    
    do {
        // reset swap
        swap = false;
        // iterate over array
        for (int i=0; i < size - 2; ++i) {
            if (list[i] > list[i + 1]) {
                // swap
                int tmp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = tmp;
                swap = true; // indicates array isn't sorted
            }
        }
    } while (swap); // if isn't sorted, continue
    return 0;
}

// improved bubble sort algorithm in lab
int bubbleSortPlus() {
    int list[size]; // initialize
    int n = size - 2;

    do {
        for (int i = 0; i < n; ++i) {
            if (list[i] > list[i + 1]) {
                int tmp = list[i + 1];
                list[i + 1] = list[i];
                list[i] = tmp;
            }
        }
        --n;
    } while (n >= 0);
}
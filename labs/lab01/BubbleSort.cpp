#include <iostream>
using namespace std;

// initial bubble sort algorithm in lab
void bubbleSort(int array[], int size)
{
    bool swap;
    
    do {
        // reset swap
        swap = false;
        // iterate over array
        for (int i=0; i < size - 2; ++i) {
            if (array[i] > array[i + 1]) {
                // swap
                int tmp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tmp;
                swap = true; // indicates array isn't sorted
            }
        }
    } while (swap); // if isn't sorted, continue
}

// improved bubble sort algorithm in lab
void bubbleSortPlus(int array[], int size)
{
    int n = size - 1;
    while (n >= 0) {
        for (int i = 0; i < n; ++i) {
            if (array[i] > array[i + 1]) {
                int tmp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tmp;
            }
        }
        --n;
    }
}

int main()
{
    int size = 5;
    int array[5] = {9, 7, 2, 6, 1};
    bubbleSortPlus(array, size);
    for (int i : array) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

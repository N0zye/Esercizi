#include <iostream>
#include <chrono>
#include <array>
#include "swap.h"

void bubbleSort(int *arr) {
	size_t size = sizeof(arr) / sizeof(arr[0]);
    int swapCounter;
    do {
        swapCounter = 0;
        for (size_t i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapCounter++;
            }
        }
    } while (swapCounter != 0);
}
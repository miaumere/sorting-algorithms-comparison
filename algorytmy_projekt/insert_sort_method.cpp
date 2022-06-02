#include "util.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>

void insertionSort(int[], int);

int _insertionSortStep = 0;

std::string  doInsertionSortWithTimers(int arr[], int arrLength, int bufferSize) {
    printf("\033[93;1;4m------------- INSERTION SORT -------------\033[0m\n\n");

    int* ascendingSortedArrayForInsertionSort = new int[arrLength];
    int* descendingSortedArrayForInsertionSort = new int[arrLength];
    int* shuffledArrayForInsertionSort = new int[arrLength];

    std::copy(arr, arr + bufferSize, ascendingSortedArrayForInsertionSort);
    std::copy(arr, arr + bufferSize, descendingSortedArrayForInsertionSort);
    std::copy(arr, arr + bufferSize, shuffledArrayForInsertionSort);

    std::sort(descendingSortedArrayForInsertionSort, descendingSortedArrayForInsertionSort + arrLength, std::greater<int>());
    std::sort(ascendingSortedArrayForInsertionSort, ascendingSortedArrayForInsertionSort + arrLength, std::less<int>());
    std::random_shuffle(shuffledArrayForInsertionSort, shuffledArrayForInsertionSort + arrLength);

    auto insertionSortTimerStart1 = std::chrono::steady_clock::now();
    insertionSort(ascendingSortedArrayForInsertionSort, arrLength);
    auto insertionSortTimerEnd1 = std::chrono::steady_clock::now();
    int timeOutput1 = std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd1 - insertionSortTimerStart1).count();


    std::cout << "\x1B[33mARR SORTED ASC - elapsed time in nanoseconds: \033[0m" << timeOutput1 << std::endl;

    std::cout << "\x1B[33mARR SORTED ASC -  actions count: \033[0m" << _insertionSortStep << std::endl;
    int action1 = _insertionSortStep;
    _insertionSortStep = 0;

    auto insertionSortTimerStart2 = std::chrono::steady_clock::now();
    insertionSort(descendingSortedArrayForInsertionSort, arrLength);
    auto insertionSortTimerEnd2 = std::chrono::steady_clock::now();
    int timeOutput2 = std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd2 - insertionSortTimerStart2).count();

    std::cout << "\x1B[93mARR SORTED DESC - elapsed time in nanoseconds: \033[0m" << timeOutput2 << std::endl;

    std::cout << "\x1B[93mARR SORTED DESC -  actions count: \033[0m" << _insertionSortStep << std::endl;
    int action2 = _insertionSortStep;
    _insertionSortStep = 0;


    auto insertionSortTimerStart3 = std::chrono::steady_clock::now();
    insertionSort(shuffledArrayForInsertionSort, arrLength);
    auto insertionSortTimerEnd3 = std::chrono::steady_clock::now();
    int timeOutput3 = std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd3 - insertionSortTimerStart3).count();
    int action3 = _insertionSortStep;
    std::cout << "\x1B[33mARR SHUFFLED - elapsed time in nanoseconds: \033[0m" << timeOutput3 << std::endl;

    std::cout << "\x1B[33mARR SHUFFLED -  actions count: \033[0m" << _insertionSortStep << std::endl << std::endl;

    return generateCsvLine("Insert sort", timeOutput1, timeOutput2, timeOutput3, action1, action2, action3);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            _insertionSortStep++;

            j = j - 1;

        }
        arr[j + 1] = key;

    }

}
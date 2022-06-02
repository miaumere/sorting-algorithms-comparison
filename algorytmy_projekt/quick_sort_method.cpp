#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>

#include "util.h"

void quickSort(int[], int, int);

int _quickSortStep = 0;

std::string  doQuickSortWithTimers(int arr[], int arrLength, int bufferSize) {
	printf("\033[32;1;4m------------- QUICK SORT -------------\033[0m\n\n");

    int* ascendingSortedArrayForQuickSort = new int[arrLength];
    int* descendingSortedArrayForQuickSort = new int[arrLength];
    int* shuffledArrayForQuickSort = new int[arrLength];

    std::copy(arr, arr + bufferSize, ascendingSortedArrayForQuickSort);
    std::copy(arr, arr + bufferSize, descendingSortedArrayForQuickSort);
    std::copy(arr, arr + bufferSize, shuffledArrayForQuickSort);

    std::sort(descendingSortedArrayForQuickSort, descendingSortedArrayForQuickSort + arrLength, std::greater<int>());
    std::sort(ascendingSortedArrayForQuickSort, ascendingSortedArrayForQuickSort + arrLength, std::less<int>());
    std::random_shuffle(shuffledArrayForQuickSort, shuffledArrayForQuickSort + arrLength);

    auto quickSortTimerStart1 = std::chrono::steady_clock::now();
    quickSort(ascendingSortedArrayForQuickSort, 0, arrLength - 1);
    auto quickSortTimerEnd1 = std::chrono::steady_clock::now();
    int timeOutput1 = std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd1 - quickSortTimerStart1).count();

    std::cout << "\x1B[32mARR SORTED ASC - elapsed time in nanoseconds: \033[0m" << timeOutput1 << std::endl;

    std::cout << "\x1B[32mARR SORTED ASC -  actions count: \033[0m"
        << _quickSortStep << std::endl;
    int action1 = _quickSortStep;
    _quickSortStep = 0;

    auto quickSortTimerStart2 = std::chrono::steady_clock::now();
    quickSort(descendingSortedArrayForQuickSort, 0, arrLength - 1);
    auto quickSortTimerEnd2 = std::chrono::steady_clock::now();
    int timeOutput2 = std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd2 - quickSortTimerStart2).count();

    std::cout << "\x1B[92mARR SORTED DESC - elapsed time in nanoseconds: \033[0m" << timeOutput1 << std::endl;

    std::cout << "\x1B[92mARR SORTED DESC -  actions count: \033[0m"
        << _quickSortStep << std::endl;
    int action2 = _quickSortStep;
    _quickSortStep = 0;


    auto quickSortTimerStart3 = std::chrono::steady_clock::now();
    quickSort(shuffledArrayForQuickSort, 0, arrLength - 1);
    auto quickSortTimerEnd3 = std::chrono::steady_clock::now();
    int timeOutput3 = std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd3 - quickSortTimerStart3).count();
    std::cout << "\x1B[32mARR SHUFFLED - elapsed time in nanoseconds: \033[0m" << timeOutput1 << std::endl;

    std::cout << "\x1B[32mARR SHUFFLED -  actions count: \033[0m" << _quickSortStep << std::endl << std::endl;
    int action3 = _quickSortStep;


    printArray(shuffledArrayForQuickSort, arrLength);

    return generateCsvLine("Quick sort", timeOutput1, timeOutput2, timeOutput3, action1, action2, action3);
}

void quickSort(int arr[], int left, int right)
{
    if (right <= left) return;

    int i, j;
    int pivot;
    i = left;
    j = right;

    pivot = arr[(left + right) / 2];
    do
    {
        while ((arr[i] < pivot) && (i < right)) i++;
        while ((pivot < arr[j]) && (j > left)) j--;
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
            _quickSortStep++;

        }
    } while (i <= j);
    if (left < j)  quickSort(arr, left, j);
    if (i < right)  quickSort(arr, i, right);
}
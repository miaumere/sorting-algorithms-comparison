#include "util.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>

int _bubbleSortStep = 0;
void bubbleSort(int[], int);

void doBubbleSortWithTimers(int arr[], int arrLength, int bufferSize) {
    printf("\033[96;1;4m------------- BUBBLE SORT -------------\033[0m\n\n");

    int* ascendingSortedArrayForBubbleSort = new int[arrLength];
    int* descendingSortedArrayForBubbleSort = new int[arrLength];
    int* shuffledArrayForBubbleSort = new int[arrLength];


    std::copy(arr, arr + bufferSize, ascendingSortedArrayForBubbleSort);
    std::copy(arr, arr + bufferSize, descendingSortedArrayForBubbleSort);
    std::copy(arr, arr + bufferSize, shuffledArrayForBubbleSort);


    std::sort(descendingSortedArrayForBubbleSort, descendingSortedArrayForBubbleSort + arrLength, std::greater<int>());
    std::sort(ascendingSortedArrayForBubbleSort, ascendingSortedArrayForBubbleSort + arrLength, std::less<int>());
    std::random_shuffle(shuffledArrayForBubbleSort, shuffledArrayForBubbleSort + arrLength);

    auto bubbleSortTimerStart1 = std::chrono::steady_clock::now();
    bubbleSort(ascendingSortedArrayForBubbleSort, arrLength);
    auto bubbleSortTimerEnd1 = std::chrono::steady_clock::now();
    std::cout << "\x1B[94mARR SORTED ASC - elapsed time in nanoseconds: \033[0m"
        << std::chrono::duration_cast<std::chrono::nanoseconds>(bubbleSortTimerEnd1 - bubbleSortTimerStart1).count() << " ns" << std::endl;

    std::cout << "\x1B[94mARR SORTED ASC -  actions count: \033[0m"
        << _bubbleSortStep << std::endl;
    _bubbleSortStep = 0;

    auto bubbleSortTimerStart2 = std::chrono::steady_clock::now();
    bubbleSort(descendingSortedArrayForBubbleSort, arrLength);
    auto bubbleSortTimerEnd2 = std::chrono::steady_clock::now();

    std::cout << "\x1B[96mARR SORTED DESC - elapsed time in nanoseconds: \033[0m"
        << std::chrono::duration_cast<std::chrono::nanoseconds>(bubbleSortTimerEnd2 - bubbleSortTimerStart2).count() << " ns" << std::endl;

    std::cout << "\x1B[96mARR SORTED DESC -  actions count: \033[0m"
        << _bubbleSortStep << std::endl;
    _bubbleSortStep = 0;


    auto bubbleSortTimerStart3 = std::chrono::steady_clock::now();
    bubbleSort(shuffledArrayForBubbleSort, arrLength);
    auto bubbleSortTimerEnd3 = std::chrono::steady_clock::now();

    std::cout << "\x1B[94mARR SHUFFLED - elapsed time in nanoseconds: \033[0m"
        << std::chrono::duration_cast<std::chrono::nanoseconds>(bubbleSortTimerEnd3 - bubbleSortTimerStart3).count() << " ns" << std::endl;

    std::cout << "\x1B[94mARR SHUFFLED -  actions count: \033[0m"
        << _bubbleSortStep << std::endl << std::endl;

}

void bubbleSort(int arr[], int lengthOfArray)
{
    int i, j;

    for (i = 0; i < lengthOfArray - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < lengthOfArray - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                _bubbleSortStep++;

            }

}

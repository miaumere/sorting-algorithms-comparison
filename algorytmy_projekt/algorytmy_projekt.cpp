#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>

void bubbleSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int);

void printArray(int[], int);

int _bubbleSortStep = 0;
int _insertionSortStep = 0;
int _quickSortStep = 0;


bool _generateRandomNumbers;

int main()
{
    int arrLength;
    std::cout << "Enter desired size of the array: ";
    std::cin >> arrLength;

    if (!std::cin.good()) {
        std::cout << "\x1B[31mWrong input! Size of array must be a valid number! \033[0m";
        return 0;
    }
    int* arr = new int[arrLength];

    const int bufferSize = arrLength;

    char generateRandomNumbersInput; 
    std::cout << "Should generate random numbers? [Y]/[N]: ";

    std::cin >> generateRandomNumbersInput;

    if (generateRandomNumbersInput == 'Y' || generateRandomNumbersInput == 'y') {
        _generateRandomNumbers = true;
    }
    else if (generateRandomNumbersInput == 'N' || generateRandomNumbersInput == 'n') {
        _generateRandomNumbers = false;
    }
    else {
        std::cout << "Invalid character. Would not generate random numbers. " << std::endl;
        _generateRandomNumbers = false;
    }

    if (_generateRandomNumbers == false) {
        std::cout << "Please give " << arrLength << " numbers to sort:" << std::endl;
    }

    for (int i = 0; i < arrLength; ++i) {
        if (_generateRandomNumbers == true) {
            arr[i] = rand();
        }
        else {
            std::cin >> arr[i];
        }
    }
    printf("\033[96;1;4m------------- BUBBLE SORT -------------\033[0m\n\n");

    #pragma region bubbleSort
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

    #pragma endregion

    printf("\033[93;1;4m------------- INSERTION SORT -------------\033[0m\n\n");

    #pragma region insertionSort
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
        std::cout << "\x1B[33mARR SORTED ASC - elapsed time in nanoseconds: \033[0m"
            << std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd1 - insertionSortTimerStart1).count() << " ns" << std::endl;

        std::cout << "\x1B[33mARR SORTED ASC -  actions count: \033[0m"
            << _insertionSortStep << std::endl;
        _insertionSortStep = 0;

        auto insertionSortTimerStart2 = std::chrono::steady_clock::now();
        insertionSort(descendingSortedArrayForInsertionSort, arrLength);
        auto insertionSortTimerEnd2 = std::chrono::steady_clock::now();

        std::cout << "\x1B[93mARR SORTED DESC - elapsed time in nanoseconds: \033[0m"
            << std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd2 - insertionSortTimerStart2).count() << " ns" << std::endl;

        std::cout << "\x1B[93mARR SORTED DESC -  actions count: \033[0m"
            << _insertionSortStep << std::endl;
        _insertionSortStep = 0;


        auto insertionSortTimerStart3 = std::chrono::steady_clock::now();
        insertionSort(shuffledArrayForInsertionSort, arrLength);
        auto insertionSortTimerEnd3 = std::chrono::steady_clock::now();

        std::cout << "\x1B[33mARR SHUFFLED - elapsed time in nanoseconds: \033[0m"
            << std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd3 - insertionSortTimerStart3).count() << " ns" << std::endl;

        std::cout << "\x1B[33mARR SHUFFLED -  actions count: \033[0m"
            << _insertionSortStep << std::endl << std::endl;

    #pragma endregion


    printf("\033[32;1;4m------------- QUICK SORT -------------\033[0m\n\n");

    #pragma region quickSort
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
        std::cout << "\x1B[32mARR SORTED ASC - elapsed time in nanoseconds: \033[0m"
            << std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd1 - quickSortTimerStart1).count() << " ns" << std::endl;

        std::cout << "\x1B[32mARR SORTED ASC -  actions count: \033[0m"
            << _quickSortStep << std::endl;
        _quickSortStep = 0;

        auto quickSortTimerStart2 = std::chrono::steady_clock::now();
        quickSort(descendingSortedArrayForQuickSort, 0, arrLength - 1);
        auto quickSortTimerEnd2 = std::chrono::steady_clock::now();

        std::cout << "\x1B[92mARR SORTED DESC - elapsed time in nanoseconds: \033[0m"
            << std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd2 - quickSortTimerStart2).count() << " ns" << std::endl;

        std::cout << "\x1B[92mARR SORTED DESC -  actions count: \033[0m"
            << _quickSortStep << std::endl;
        _quickSortStep = 0;


        auto quickSortTimerStart3 = std::chrono::steady_clock::now();
        quickSort(shuffledArrayForQuickSort, 0, arrLength - 1);
        auto quickSortTimerEnd3 = std::chrono::steady_clock::now();

        std::cout << "\x1B[32mARR SHUFFLED - elapsed time in nanoseconds: \033[0m"
            << std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd3 - quickSortTimerStart3).count() << " ns" << std::endl;

        std::cout << "\x1B[32mARR SHUFFLED -  actions count: \033[0m"
            << _quickSortStep << std::endl << std::endl;


    #pragma endregion
        printArray(shuffledArrayForQuickSort, arrLength);

    return 0;
}

#pragma region bubbleSort functions
    void bubbleSort(int arr[], int lengthOfArray)
    {      
        int i, j;
        bool swapped;
        for (i = 0; i < lengthOfArray - 1; i++) {
            swapped = false;

            for (j = 0; j < lengthOfArray - i - 1; j++) {

                if (arr[j] > arr[j + 1]) {

                    std::swap(arr[j], arr[j + 1]);
                    _bubbleSortStep++;
                    swapped = true;

              }
            }     
            if (swapped == false)
                break;
        }

    }
#pragma endregion 

#pragma region insertionSort functions
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
#pragma endregion

#pragma region quickSort functions
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
#pragma endregion


// A utility function to print an array of size 'size' - used for debugging purpose
    void printArray(int arr[], int size)
    {
        printf("\033[95;1;4m------------- Sorted array -------------\033[0m\n\n");

            int i;
            for (i = 0; i < size; i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
       
    }

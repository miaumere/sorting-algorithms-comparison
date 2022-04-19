#include <iostream>
#include <algorithm>
#include <chrono>


void bubbleSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int, int);

void printArray(int[], int);
void swapArrayFields(int*, int*);


int main()
{
    const int arrLength = 10;
    const int bufferSize = 10;
    int arr[arrLength];
    std::cout << "Please give 10 numbers to sort:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }

    #pragma region bubbleSort
        int arrayForBubbleSort[arrLength];
        std::copy(arr, arr + bufferSize, arrayForBubbleSort);

        auto bubbleSortTimerStart = std::chrono::steady_clock::now();
        bubbleSort(arrayForBubbleSort, arrLength);
        auto bubbleSortTimerEnd = std::chrono::steady_clock::now();

        std::cout << "bubbleSort elapsed time in nanoseconds: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(bubbleSortTimerEnd - bubbleSortTimerStart).count()
            << " ns" << std::endl;
    #pragma endregion

    #pragma region insertionSort
        int arrayForInsertionSort[arrLength];
        std::copy(arr, arr + bufferSize, arrayForInsertionSort);

        auto insertionSortTimerStart = std::chrono::steady_clock::now();
        insertionSort(arr, arrLength);
        auto insertionSortTimerEnd = std::chrono::steady_clock::now();
        std::cout << "insertionSort elapsed time in nanoseconds: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd - insertionSortTimerStart).count()
            << " ns" << std::endl;
    #pragma endregion

    #pragma region quickSort
        int arrayForQuickSort[arrLength];
        std::copy(arr, arr + bufferSize, arrayForQuickSort);

        auto quickSortTimerStart = std::chrono::steady_clock::now();
        int actionCount = 0;
        quickSort(arr, 0, arrLength - 1, actionCount);
        auto quickSortTimerEnd = std::chrono::steady_clock::now();

        std::cout << "quickSort elapsed time in nanoseconds: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd - quickSortTimerStart).count()
            << " ns" << std::endl;

    #pragma endregion

    std::cout << "sorted array: \n";
    printArray(arr, arrLength);

    return 0;
}

#pragma region bubbleSort functions
    void bubbleSort(int arr[], int lengthOfArray)
    {   
        int actionsCount = 0;
        int i, j;
        for (i = 0; i < lengthOfArray - 1; i++) {
            actionsCount += 1;
            for (j = 0; j < lengthOfArray - i - 1; j++) {
                actionsCount += 1;

                if (arr[j] > arr[j + 1]) {
                    actionsCount += 1;

                    swapArrayFields(&arr[j], &arr[j + 1]);
              }
            }      
        }
        std::cout << "bubbleSort actionsCount: " << actionsCount << std::endl;
    }
#pragma endregion 

#pragma region insertionSort functions
    void insertionSort(int arr[], int n)
    {
        int actionsCount = 0;
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;
            actionsCount += 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
                actionsCount += 1;

            }
            arr[j + 1] = key;           
            actionsCount += 1;

        }
        std::cout << "insertionSort actionsCount: " << actionsCount << std::endl;

    }
#pragma endregion

#pragma region quickSort functions
    int partition(int arr[], int low, int high, int actionsCount)
    {
        int pivot = arr[high]; 
        int i = (low - 1);


        for (int j = low; j <= high - 1; j++)
        {
            actionsCount += 1;
            if (arr[j] < pivot)
            {
                i++;
                actionsCount += 1;

                swapArrayFields(&arr[i], &arr[j]);
            }
        }
        swapArrayFields(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

    void quickSort(int arr[], int low, int high, int actionsCount)
    {
        actionsCount += 1;

        if (low < high)
        {
            int pi = partition(arr, low, high, actionsCount);
            actionsCount += 1;

            quickSort(arr, low, pi - 1, actionsCount);
            quickSort(arr, pi + 1, high, actionsCount);
        }
        std::cout << "quickSort actionsCount: " << actionsCount << std::endl;

    }

#pragma endregion


// A utility function to print an array of size 'size' - used for debugging purpose
    void printArray(int arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

// A utility function to swap two elements
    void swapArrayFields(int* xp, int* yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
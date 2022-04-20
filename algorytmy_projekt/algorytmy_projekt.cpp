#include <iostream>
#include <algorithm>
#include <chrono>


void bubbleSort(int[], int);
void insertionSort(int[], int);
void quickSort(int[], int, int);

void printArray(int[], int);
void swapArrayFields(int*, int*);

int _bubbleSortStep = 0;
int _insertionSortStep = 0;
int _quickSortStep = 0;



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

        std::cout << "bubbleSort actions count: " << _bubbleSortStep << std::endl;


        std::cout << "sorted array: \n";
        printArray(arrayForBubbleSort, arrLength);

    #pragma endregion

    #pragma region insertionSort
        int arrayForInsertionSort[arrLength];
        std::copy(arr, arr + bufferSize, arrayForInsertionSort);

        auto insertionSortTimerStart = std::chrono::steady_clock::now();
        insertionSort(arrayForInsertionSort, arrLength);
        auto insertionSortTimerEnd = std::chrono::steady_clock::now();
        std::cout << "insertionSort elapsed time in nanoseconds: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(insertionSortTimerEnd - insertionSortTimerStart).count()
            << " ns" << std::endl;

        std::cout << "insertionSort actions count: " << _insertionSortStep << std::endl;


        std::cout << "sorted array: \n";
        printArray(arrayForInsertionSort, arrLength);

    #pragma endregion

    #pragma region quickSort
        int arrayForQuickSort[arrLength];
        std::copy(arr, arr + bufferSize, arrayForQuickSort);

        auto quickSortTimerStart = std::chrono::steady_clock::now();
        quickSort(arrayForQuickSort, 0, arrLength - 1);
        auto quickSortTimerEnd = std::chrono::steady_clock::now();

        std::cout << "quickSort elapsed time in nanoseconds: "
            << std::chrono::duration_cast<std::chrono::nanoseconds>(quickSortTimerEnd - quickSortTimerStart).count()
            << " ns" << std::endl;

        std::cout << "quickSort actions count: " << _quickSortStep << std::endl;


        std::cout << "sorted array: \n";
        printArray(arrayForQuickSort, arrLength);

    #pragma endregion


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
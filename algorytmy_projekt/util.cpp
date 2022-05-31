#include <iostream>

// An utility function to print an array of size 'size' - used for debugging purpose
void printArray(int arr[], int size)
{
    printf("\033[95;1;4m------------- Sorted array -------------\033[0m\n\n");

    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}


// An utility function to swap items in array
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
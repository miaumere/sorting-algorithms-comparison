#include <iostream>
#include <string>

// An utility function to print an array of size 'size' - used for debugging purpose
void printArray(int arr[], int size)
{
    printf("\033[95;1;4m------------- Sorted array -------------\033[0m\n\n");

    int i;
    for (i = 0; i < size; i++)
        std::cout << "\x1B[95m" << arr[i] << "\033[0m" << " ";

    std::cout << std::endl;
}


// An utility function to swap items in array
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An utility function to return string for .csv file
std::string generateCsvLine(std::string algorithmType, int timeOutput1, int action1, int timeOutput2, int action2, int timeOutput3, int action3) {

    return algorithmType + ";" 
        + std::to_string(timeOutput1) 
        + ";" 
        + std::to_string(action1)
        + ";"
        + std::to_string(timeOutput2)
        + ";"
        + std::to_string(action2)
        + ";"
        + std::to_string(timeOutput3)
        + ";"
        + std::to_string(action3)
        + "\n";
}
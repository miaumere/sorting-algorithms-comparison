#include <iostream>
#include <algorithm>
#include <chrono>
#include <stdlib.h>
#include <ios>
#include <fstream>

#include "sort_algorithms.h"
#include <stdio.h>
#include <wchar.h>
#include <windows.h>

bool _generateRandomNumbers;


int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }

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

    std::ofstream file;
    file.open("example.csv");

    file << "Nazwa algorytmu;" 
        << "Czas dla tablicy posortowanej rosnaco; Czas dla tablicy posortowanej malejaco; Czas dla tablicy nieposortowanej; "
        << "Ilosc akcji dla tablicy posortowanej rosnaco; Ilosc akcji dla tablicy posortowanej malejaco; Ilosc akcji dla tablicy posortowanej nieposortowanej; \n";


    file << doBubbleSortWithTimers(arr, arrLength, bufferSize);

    doInsertionSortWithTimers(arr, arrLength, bufferSize);

    doQuickSortWithTimers(arr, arrLength, bufferSize);


    file.close();


    std::cin.ignore();
    std::cin.ignore();

    return 0;
}

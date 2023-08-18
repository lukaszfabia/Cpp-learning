#include <iostream>
#include <chrono>
#include "task4.h"

using namespace std;

void randomizeArray(int *arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

void iterateWithPointer(int *arr, int size)
{
    for (int *i = arr; i < arr + size; i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}

void iterateWithIndex(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void allocateWithPointer(int *arr, int size)
{
    for (int *i = arr; i < arr + size; i++)
    {
        *i += 1000;
    }
}

void allocateWithIndex(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] += 1000;
    }
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    // randomizeArray(arr, size)

    auto start = chrono::high_resolution_clock::now();
    allocateWithIndex(arr, size); // normal way to iterate through array
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by index: " << duration.count() << " ms" << endl;

    start = chrono::high_resolution_clock::now();
    allocateWithPointer(arr, size); // low-end way to iterate through array
    end = chrono::high_resolution_clock::now();

    duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken by pointer: " << duration.count() << " ms" << endl;

    delete[] arr;

    system("pause");

    return 0;
}

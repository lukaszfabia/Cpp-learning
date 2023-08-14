// note: when u work on array u dont need to use &arr[i] to get address of element but when u use
// non array vars you have to "&" when you giving variable to function when there is declarated pointer in argument of function

#include <iostream>
#include <cstdlib>
#include "task3.h"

using namespace std;

int len;

int main()
{
    int *arr = new int[len];
    printf("Enter length of array: ");
    cin >> len;
    randomize(arr);
    printf("Sum of array: %d\n", sum(arr));
    printf("Average of array: %.2f\n", average(arr));
    iter(arr);
    printf("\n");
    reverse(arr);
    iter(arr);
    add(arr, 5);
    iter(arr);
    add(arr, -1, 2);
    add(arr, 10, len);
    iter(arr);

    delete[] arr;

    return 0;
}

void randomize(int *arr)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        *arr = rand() % 100 + 1;
        arr++;
    }
}

int sum(int *arr)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += *arr;
        arr++;
    }
    return sum;
}

float average(int *arr)
{
    return (float)sum(arr) / len;
}

void iter(int *arr)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *arr);
        arr++;
    }
    printf("\n");
}

void reverse(int *arr)
{
    // O(len/2)
    int *start = arr;
    int *end = arr+len-1;
    while (start<end)
    {
        swap(*start, *end);
        start++, end--;
    }
}

bool add(int *arr, int element){
    int *end = len+arr;
    len++;
    *end = element;

    return true;
}

bool add(int *arr, int element, int index){
    if (index>len || index<0){
        return false;
    }
    else{
        int *end = len+arr;
        len++;
        while (end>arr+index)
        {
            *end = *(end-1);
            end--;
        }
        *end = element;
        return true;
    }
}
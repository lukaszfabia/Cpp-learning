#ifndef TASK3_H
#define TASK3_H

void randomize(int *arr); // set random numbers to array
void iter(int *arr);      // iterate through array (print all elements)
int sum(int *arr);
float average(int *arr);
void reverse(int *arr);
bool add(int *arr, int element);
bool add(int *arr, int element, int index); // add element to array at index (index must be < len)

#endif

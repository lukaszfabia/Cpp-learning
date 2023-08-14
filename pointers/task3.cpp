#include <iostream>
#include <cstdlib>

using namespace std;

int len;
void randomize(int *arr); // set random numbers to array
void iter(int *arr); // iterate through array (print all elements
int sum(int *arr);
float average(int *arr);

int main()
{
    int *arr = new int [len];
    cout << "Enter length of array: ";
    cin >> len;
    randomize(arr);
    cout << "Sum of array: " << sum(arr) << endl;
    cout << "Average of array: " << average(arr) << endl;
    iter(arr);
    delete [] arr;

    return 0;
}

void randomize(int *arr){
    srand(time(NULL));
    for (int i = 0; i<len; i++){
        *arr = rand() % 100+1;
        arr++;
    }
}

int sum(int *arr){
    int sum = 0;
    for (int i = 0; i<len; i++){
        sum += *arr;
        arr++;
    }
    return sum;
}

float average(int *arr){
    return (float)sum(arr)/len;
}

void iter(int *arr){
    for (int i = 0; i<len; i++){
        printf("%d ", *arr);
        arr++;
    }
}
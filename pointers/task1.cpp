#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int amount, start, finish;
double res;

int main()
{
    cin >> amount;
    int *arr = new int[amount];
    start = clock();
    for (int i = 0; i < amount; i++)
    {
        arr[i] += 100;
    }
    finish = clock();

    res = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Time: " << res << endl;

    delete[] arr;



    int *pointer = new int[amount];
    start = clock();

    for (int i = 0; i < amount; i++)
    {
        *pointer += 100;
        pointer++;
    }
    finish = clock();

    res = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "Time with pointer: " << res << endl;

    delete[] arr;

    return 0;
}

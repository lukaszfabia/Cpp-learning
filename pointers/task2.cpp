// u have 3 numbers and sort by using pointers
#include <iostream>

using namespace std;

void sort(int *x, int *y, int *z); // send originals to function

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    sort(&x, &y, &z); // giving adresses to variables 
    cout << x << " " << y << " " << z << endl;

    system("pause");
    return 0;
}

void sort(int *x, int *y, int *z)
{
    if (*x > *y)
    {
        swap(*x, *y);
    }
    if (*x > *z)
    {
        swap(*x, *z);
    }
    if (*y > *z)
    {
        swap(*y, *z);
    }
}

#include <iostream>

using namespace std;

int main()
{
    unsigned short int a = 4, b = 3;
    // 4 = 0000 0100
    // 3 = 0000 0011
    
    // operatory bitowe

    // koniunkcja
    cout << (a & b) << "=0" << endl;

    // alternatywa wykluczajaca
    cout << (a ^ b) << "=7" << endl;

    // alternatywa
    cout << (a | b) << "=7" << endl;

    // przesuniecie bitowe w lewo
    cout << (a << 1) << "=8" << endl;

    // przesuniecie bitowe w prawo
    cout << (a >> 1) << "=2" << endl;


    return 0;
}
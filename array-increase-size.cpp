# include <iostream>
using namespace std;

int main()
{
    int *p = new int[5];
    int *q = new int[10];

    p[0] = 5; p[1] = 8; p[2] = 9; p[3] = 6; p[4] = 5;
    // cannot p = {5, 8, 9, 6, 5}; due to 1. p is a pointer, not an array.
    // 2. {5, 8, 9, 6, 5} is an initializer list, which cannot be assigned to a pointer.
    // 3. Dynamic arrays are allocated in the heap at runtime, and C++ does not track their size like static arrays.
    for(int i=0; i<5; i++)
        cout << p[i] << "\n";
    
    cout << endl;

    for(int n=0; n<5; n++)
        q[n] = p[n];

    for(int i=0; i<10; i++)
        cout << q[i] << "\n";
    
    delete []p;
    p = q;
    q = NULL;
    
    return 0;
}
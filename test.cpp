#include <iostream>
using namespace std;

int f(int &x, int c);

int main()
{
    int a = 5;  // Declare a variable instead of passing a literal
    cout << f(a, 5) << endl; // Call the function correctly and print the result
    return 0;
}

int f(int &x, int c) 
{
    c = c - 1; 
    if (c == 0) return 1; 
    x = x + 1; 
    return f(x, c) * x;
}

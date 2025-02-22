# include <iostream>
using namespace std;

int Fac_Recursion(int n);
int Fac_For_Loop(int n);

int main()
{
    int n;
    cout << "Enter a number n: ";
    cin >> n;
    cout << "The Factorial of " << n << " is: " << Fac_Recursion(n) << endl;
    cout << "The Factorial of " << n << " is: " << Fac_For_Loop(n) << endl;
    return 0;
}

int Fac_Recursion(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return Fac_Recursion(n-1) * n;
    }
}

int Fac_For_Loop(int n)
{
    int Fac = 1;
    for (int i = 1; i <= n; i++)
    {
        Fac *= i;
    }
    return Fac;
}
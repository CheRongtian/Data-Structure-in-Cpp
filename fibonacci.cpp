# include <iostream>
using namespace std;

int fib(int n);
int fib_loop(int n);
int fib_memorization(int n);

int main()
{
    int n;
    cout << "Enter a number n: ";
    cin >> n;
    int F[n];
    cout << "The answer of fib(" << n << ") is: " << fib(n) << endl;
    cout << "The answer of fib(" << n << ") is: " << fib_loop(n) << endl;
    cout << "The answer of fib(" << n << ") is: " << fib_memorization(n) << endl;
    return 0;
}

int fib(int n)
{
    if(n < 2)
    {
        return n;
    }
    else
    {
        return fib(n-1) + fib(n-2);
    }
}

int fib_loop(int n)
{
    int f0 = 0, f1 = 1, sum = 0;
    if(n < 2)
    {
        return n;
    }

    for(int i=2; i<=n; i++)
    {
        sum = f0+f1;
        f0 = f1;
        f1 = sum;
    }
    return sum;
}

int fib_memorization(int n)
{
    int F[n];
    if (n < 2)
    {
        F[n] = n;
        return n;
    }
    if (F[n-2] == -1)   // Not recorded
    {
        F[n-2] = fib_memorization(n-2);
    }
    if(F[n-1] == -1)
    {
        F[n-1] = fib_memorization(n-1);
    }
    
    return fib_memorization(n-1) + fib_memorization(n-2);
    
}
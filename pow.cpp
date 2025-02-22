# include <iostream>
using namespace std;

int pow1(int m, int n);
int pow2(int m, int n);

int main()
{   int m, n;
    cout << "Enter the number m, n: ";
    cin >> m >> n;
    cout << "The result of pow(" << m << ", " << n << ") is: " << pow1(m, n) << endl;
    cout << "The result of pow(" << m << ", " << n << ") is: " << pow2(m, n) << endl;
    return 0;
}

int pow1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return m * pow1(m,n-1);
    }
}

int pow2(int m, int n)
{
    if(n == 0)
    {
        return 1;
    }
    if (n % 2 ==0) // n is even
    {
        return pow2(m*m, n/2);
    }
    else
    {
        return m*pow2(m*m, (n-1)/2);
    }
    
}
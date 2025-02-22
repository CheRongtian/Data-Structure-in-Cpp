# include <iostream>
using namespace std;

int e(int x, int n);
int e_loop(int x, int n);
int e_Horner_Rule(int x, int n);

int main()
{
    int x, n;
    cout << "Enter 2 number x, n: ";
    cin >> x >> n;
    cout << "The result of Taylor Series for the e^" << x << " is: " << e(x,n)<< endl;
    cout << "The result of Taylor Series for the e^" << x << " is: " << e_loop(x,n)<< endl;
    cout << "The result of Taylor Series for the e^" << x << " is: " << e_Horner_Rule(x,n)<< endl;
    return 0;
}

int e(int x, int n)
{
    static int p = 1, f = 1;
    int r = 1;

    if(n == 0)
    {
        return 1;
    }
    else
    {
        r = e(x, n-1);
        p *= x;
        f *= n;
        return r + p/f;
    }
}

int e_loop(int x, int n)
{
    int r = 1;
    for (;n > 0; n--)
    {
        r = 1+(x/n)*r;
    }
    return r;
}

int e_Horner_Rule(int x, int n)
{
    static int r = 1;
    if (n == 0)
    {
        return r;
    }
    else
    {
        r = 1 + (x/n)*r;
        return e_Horner_Rule(x, n-1);
    }
}
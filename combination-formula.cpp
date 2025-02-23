# include <iostream>
using namespace std;

int C(int m, int n);

int main()
{
    int m, n;
    cout << "Enter 2 number m, n: ";
    cin >> m >> n;
    cout << "The result of C" << m << " " << n << "is " << C(m,n) << endl;
    return 0;
}

int C(int m, int n)
{
    if(m == 0 || m == n)
    {
        return 1;
    }
    else
    {
        return C(m-1,n-1) + C(m,n-1);
    }
}
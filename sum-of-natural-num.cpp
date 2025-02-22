# include <iostream>
using namespace std;

int Sum_Recursion(int n);
int Sum_For_Loop(int n);
int Sum_Formula(int n);

int main()
{
    int n;
    cout << "Enter a number n: ";
    cin >> n;
    cout << "The sum of 0 to n is: " << Sum_Recursion(n) << endl;
    cout << "The sum of 0 to n is: " << Sum_For_Loop(n) << endl;
    cout << "The sum of 0 to n is: " << Sum_Formula(n) << endl;
    return 0;
}

int Sum_Recursion(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        return Sum_Recursion(n-1) + n;
    }
}

int Sum_For_Loop(int n)
{
    int sum = 0;
    for (int i; i <= n; i++)
    {
        sum +=i;
    }
    return sum;
}

int Sum_Formula(int n)
{
    return n*(n+1)/2;
}
# include <iostream>
using namespace std;

void TOH(int n, int A, int B, int C);

int main()
{
    int n, A, B, C;
    cout << "Enter how many disks the Tower of Hanoi should have, n = ";
    cin >> n;
    cout << "The steps for solving " << n << " disks within the Tower of Hanoi are listed: " << endl;
    TOH(n,1,2,3);
    return 0;
}

void TOH(int n, int A, int B, int C)
{
    if(n >0)
    {
        TOH(n-1, A, C, B);
        cout << "From (" << A << " to " << C << ")" << endl;
        TOH(n-1, B, A, C);
    }
}
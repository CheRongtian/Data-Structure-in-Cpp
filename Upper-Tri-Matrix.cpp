# include <iostream>
using namespace std;

class Upper_Tri_M
{
    private:
        int *A;
        int n;
    public:
        Upper_Tri_M()
        {
            n=2;
            A=new int [2*(2+1)/2];
        }
        Upper_Tri_M(int n)
        {
            this->n = n; 
            A = new int [n*(n+1)/2];
        }
        ~Upper_Tri_M()
        {
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
};
void Upper_Tri_M::Set(int i, int j, int x)
{
    if(i<=j) A[(2*n-i+2)*(i-1)/2 + j-i] = x; //change to A[j(j-1)/2+i-1] to col-major
}

int Upper_Tri_M::Get(int i, int j)
{
    if(i<=j) return A[(2*n-i+2)*(i-1)/2 + j-i];
    return 0;
}

void Upper_Tri_M::Display()
{
    for(int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if(i<=j) cout<<A[(2*n-i+2)*(i-1)/2 + j-i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    Upper_Tri_M lm(d);

    int x;
    cout << "Enter All Elements: ";
    for(int i = 1; i<=d; i++)
    {
        for(int j = 1; j<=d; j++)
        {
            cin>>x;
            lm.Set(i, j, x);
        }
    }

    cout<<endl;
    lm.Display();

    return 0;
}
# include <iostream>
using namespace std;

class Lower_Tri_M
{
    private:
        int *A;
        int n;
    public:
        Lower_Tri_M()
        {
            n=2;
            A=new int [2];
        }
        Lower_Tri_M(int n)
        {
            this->n = n; //this->n : n in private
            A = new int [n];
        }
        ~Lower_Tri_M()
        {
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
};
void Lower_Tri_M::Set(int i, int j, int x)
{
    if(i==j) A[i-1] = x;
}

int Lower_Tri_M::Get(int i, int j)
{
    if(i==j) return A[i-1];
    return 0;
}

void Lower_Tri_M::Display()
{
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if(i==j) cout<<A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    Lower_Tri_M d(4);

    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,9);
    d.Set(4,4,12);

    d.Display();
    return 0;
}
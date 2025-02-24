# include <iostream>
using namespace std;

struct Array 
{
    int A[10];
    int size;
    int length;
};

void display(struct Array array)
{
    for(int i=0; i< array.length; i++)
        cout << array.A[i] << " ";
    cout << endl;
}

void add(struct Array *array, int x)
{
    if(array -> length >= array -> size)
    {
        cout << "Exceed Error" << endl;
        return; // break is for loop
    }
    else
        array -> A[array->length++] = x;
}

void insert(struct Array *array, int index, int x)
{
    if (index >= 0 && index < array -> length)
    {
        for (int i = array -> length; i > index; i--)
            array -> A[i] = array -> A[i-1];
        array -> A[index] = x;
        array -> length ++;
    }
}

int main()
{
    struct Array A = {{2, 3, 4, 5, 6}, 20, 5};
    add(&A,10);
    display(A);
    insert(&A, 2, 100);
    display(A);
    return 0;
}
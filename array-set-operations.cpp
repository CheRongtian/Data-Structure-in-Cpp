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

void union_unsorted(struct Array *array, struct Array *array2, struct Array *array3)
{
    int i = 0;
    int j = 0; 
    int k = 0;
    
    while(i<array->length)
    {
        array3->A[k++] = array->A[i++];
    }

    for(; j<array2->length; j++)
    {
        bool overlap = false;
        for(int i = 0; i<array->length; i++)
        {
            if(array2->A[j] == array->A[i])
            {
                overlap = true;
                break;
            }
        }
    if(!overlap)
    {
        array3->A[k++] = array2->A[j];
    }
    }
}

int main()
{   
    struct Array A = {{3, 5, 10, 4, 6}, 5, 5};
    struct Array B = {{2, 4, 5, 7, 12}, 5, 5};
    struct Array C = {{}, 10, 10};
    union_unsorted(&A, &B, &C);
    display(C);
    return 0;
}
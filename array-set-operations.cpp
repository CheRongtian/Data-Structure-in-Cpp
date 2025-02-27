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
    array3 ->length = k;
}

void union_sorted(struct Array *array, struct Array *array2, struct Array *array3)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while(i<array->length && j<array2->length)
    {
        if(array->A[i] < array2->A[j])
            array3->A[k++] = array->A[i++];
        if(array->A[i] > array2->A[j])
            array3->A[k++] = array2->A[j++];
        else
        {
            array3->A[k++] = array2->A[j++];
            i++;
        }
    }
    // Copy remaining elements from array1
    while (i < array->length)
        array3->A[k++] = array->A[i++];

    while (j < array2->length)
        array3->A[k++] = array2->A[j++];
    
    array3->length = k;
}

int main()
{   
    struct Array A = {{3, 5, 10, 4, 6}, 5, 5};
    struct Array B = {{2, 4, 5, 7, 12}, 5, 5};
    struct Array C = {{}, 10, 0};
    union_unsorted(&A, &B, &C);
    display(C);

    struct Array A1 = {{3, 4, 5, 6, 10}, 5, 5};
    struct Array B1 = {{2, 4, 5, 7, 12}, 5, 5};
    struct Array C1 = {{}, 10, 0};
    union_sorted(&A1, &B1, &C1);
    display(C1);    
    return 0;
}
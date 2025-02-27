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

    // Copy remaining elements from array1
    while (i < array->length)
        array3->A[k++] = array->A[i++];

    while (j < array2->length)
        array3->A[k++] = array2->A[j++];
    
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

void intersection_unsorted(struct Array *array, struct Array *array2, struct Array *array3)
{
    int k = 0;
    for(int i = 0; i<array->length;i++)
    {
        for (int j = 0; j<array2->length; j++)
        {
            if(array->A[i]==array2->A[j])
                array3->A[k++] = array->A[i];
        }
    }
    array3->length = k;
}

void intersection_sorted(struct Array *array, struct Array *array2, struct Array *array3)
{   
    int i = 0;
    int k = 0;
    int j = 0;

    while(i<array->length && j<array2->length)
    {
        if(array->A[i]<array2->A[j])
            i++;
        else if(array->A[i]>array2->A[j])
            j++;
        else
        {
            array3->A[k] = array->A[i];
            i++;j++;k++;
        }
    }

    array3->length = k;
}

void difference_unsorted(struct Array *array, struct Array *array2, struct Array *array3)
{
    int k = 0;
    for (int i = 0; i<array->length;i++)
    {
        bool found = false;
        for(int j = 0; j<array2->length; j++)
        {
            if(array->A[i] == array2->A[j])
            {
                found = true;
                break;
            }
        }
        if(!found)  // !found <=> found == false
            array3->A[k++] = array->A[i];
    }
    array3->length = k;
}

void difference_sorted(struct Array *array, struct Array *array2, struct Array *array3)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<array->length && j<array2->length)
    {
        if(array->A[i]<array2->A[j])
        {
            array3->A[k++] = array->A[i];
            i++;
        }
        else if(array->A[i]>array2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    array3->length = k;
}

int main()
{   
    struct Array A = {{3, 5, 10, 4, 6}, 5, 5};
    struct Array B = {{2, 4, 5, 7, 12, 8}, 6, 6};
    struct Array C = {{}, 10, 0};
    union_unsorted(&A, &B, &C);
    display(C);

    struct Array A1 = {{3, 4, 5, 6, 10}, 5, 5};
    struct Array B1 = {{2, 4, 5, 7, 11, 12}, 6, 6};
    struct Array C1 = {{}, 10, 0};
    union_sorted(&A1, &B1, &C1);
    display(C1);
    
    struct Array A2 = {{3, 5, 10, 4, 10}, 5, 5};
    struct Array B2 = {{2, 4, 5, 7, 12, 8}, 6, 6};
    struct Array C2 = {{}, 10, 0};
    intersection_unsorted(&A2, &B2, &C2);
    display(C2);

    struct Array A3 = {{3, 4, 5, 6, 10}, 5, 5};
    struct Array B3 = {{2, 4, 5, 7, 11, 12}, 6, 6};
    struct Array C3 = {{}, 10, 0};
    intersection_sorted(&A3, &B3, &C3);
    display(C3);

    struct Array A4 = {{3, 5, 10, 4, 6}, 5, 5};
    struct Array B4 = {{2, 4, 5, 7, 12, 8}, 6, 6};
    struct Array C4 = {{}, 10, 0};
    difference_unsorted(&A4, &B4, &C4);
    display(C4);

    struct Array A5 = {{3, 4, 5, 6, 10}, 5, 5};
    struct Array B5 = {{2, 4, 5, 7, 8, 12}, 6, 6};
    struct Array C5 = {{}, 10, 0};
    difference_sorted(&A5, &B5, &C5);
    display(C5);

    return 0;
}
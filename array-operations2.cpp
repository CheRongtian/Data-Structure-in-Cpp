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

void insert_in_sorted(struct Array *array, int n)
{
    int i = array -> length - 1;
    while(array -> A[i] > n)
    {
        array -> A[i+1] = array -> A[i];
        i--;
    }
    array -> A[i+1] = n;
    array -> length ++;
}

int is_sorted(struct Array *array, int n)
{
    for(int i=0; i<n-1; i++)
    {
        if(array -> A[i] > array -> A[i+1])
            return false;
    }
    return true;
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void arrange_or_not(struct Array *array, int n)
{
    int i = 0;
    int j = array -> length - 1;
    while(i<j)
    {
        while(array -> A[i]<0){i++;}
        while(array -> A[j]>=0){j--;}
        if(i<j)
            swap(array -> A[i], array -> A[j]);
    }
}

void merge(struct Array *array, struct Array *array2, struct Array *array3)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < array -> length-1 && j < array2 -> length - 1)
    {
        if(array -> A[i] < array2 -> A[j])
            array3 -> A[k++] = array -> A[i++];
        else
            array3 -> A[k++] = array2 -> A[j++];
    }
    for(; i < array -> length; i++)
        array3 -> A[k++] = array ->A [i];
    for(; j < array2 -> length; j++)
        array3 -> A[k++] = array2 ->A [j];
}

int main()
{
    struct Array A = {{4,8,13,16,20,25,28,33}, 10, 8};
    display(A);
    insert_in_sorted(&A, 18);
    display(A);
    if(is_sorted(&A, A.length) != false)
        cout << "The array is sorted." << endl;
    else
        cout << "The array is unsorted." << endl;
    
    cout << endl;

    struct Array B = {{-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 10, 10};
    display(B);
    arrange_or_not(&B, B.length);
    display(B);

    cout << endl;

    struct Array C = {{3, 8, 16, 20, 25}, 5, 5};
    struct Array D = {{4, 10, 12, 13}, 4, 4};
    struct Array E = {{}, 9, 9};
    merge(&C, &D, &E);
    cout << "C: ";
    display(C);
    cout << "D: ";
    display(D);
    cout << "E: ";
    display(E);

    return 0;
}
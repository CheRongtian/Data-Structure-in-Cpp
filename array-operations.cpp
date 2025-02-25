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

void del(struct Array *array, int index)
{
    int x = array -> A[index];
    for (int i = index; i < (array -> length) - 1; i++)
        array -> A[i] = array -> A[i+1];
    array -> length --;
}

int linear_search(struct Array *array, int x)
{
    int i;
    for(i = 0; i < array ->length; i++)
    {
        if(array ->A[i] == x)
            return i;   // successful
    }
    return -1; // unsuccesful
}

int get(struct Array *array, int index)
{
    if(index >=0 && index < array -> length)
        return array -> A[index];
    return -1;
}

void set(struct Array *array, int index, int x)
{
    if(index >=0 && index < array -> length)
        array -> A[index] = x;
}

int max(struct Array *array)
{
    int max = array -> A[0];
    for(int i = 1; i < array -> length; i++)
    {
        if(array -> A[i] > max)
            max = array -> A[i];
    }
    return max;
}

int sum(struct Array *array)
{
    int total = 0;
    for(int i = 0; i < array -> length; i++)
        total += array -> A[i];
    return total;
}

int sum2(struct Array *array, int n)
{
    if(n<0)
        return 0;
    else
        return sum2(array, n-1) + array -> A[n];
}

int avg(struct Array *array, int n)
{
    int total = 0;
    for(int i = 0; i < array -> length; i++)
        total += array -> A[i];
    return total/n;
}

void reverse1(struct Array *array)
{
    int *B;
    B = new int[array -> length]; // Use another array to store the reversed array first

    for(int i = array -> length-1, j = 0 ; i >= 0; i--,j++)
        B[j] = array -> A[i];
    for(int i = 0; i < array -> length; i++)
        array -> A[i] = B[i];
    
    delete[] B; // Free memeory to prevent leaks
}

void reverse2(struct Array *array)
{
    for(int i = 0, j = array -> length-1; i < j; i++, j--)
    {
        int temp;
        temp = array -> A[i];
        array -> A[i] = array -> A[j];
        array -> A[j] = temp;
    }
}

void left_rotate(struct Array *array)
{
    int temp;
    temp = array -> A[0];
    for (int i = 1; i < array -> length; i++)
        array -> A[i-1] = array -> A[i];
    array -> A[array -> length - 1] = temp;
}

int main()
{
    struct Array A = {{2, 3, 4, 5, 6}, 20, 5};
    add(&A,10);
    display(A);
    insert(&A, 2, 100);
    display(A);
    del(&A, 2);
    display(A);
    
    int result = linear_search(&A, 100);
    if(result != -1)
        cout << "The index of the targeted value is: " << result << endl;
    else
        cout << "There is no such value in the array." << endl;

    cout << get(&A, 3) << endl;
    set(&A, 3, 100);
    cout << get(&A, 3) << endl;
    display(A);

    cout << "The biggest element in the array is: " << max(&A) <<endl;
    cout << "The sum element in the array is: " << sum(&A) <<endl;
    cout << "The sum element in the array is: " << sum2(&A, A.length-1) <<endl;
    cout << "The average element in the array is: " << avg(&A, A.length-1) <<endl;

    reverse1(&A);
    display(A);

    reverse2(&A);
    display(A);

    left_rotate(&A);
    display(A);
    
    return 0;
}
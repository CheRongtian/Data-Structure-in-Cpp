# include <iostream>
using namespace std;

struct Array
{
    int A[15];
    int size;
    int length;
};

int Binary_Search(struct Array array, int key)
{
    int low, high, mid;
    low = 0; high = array.length -1; 
    while(high >= low)
    {
        mid = (high + low) / 2;
        if(array.A[mid] == key)
            return mid;
        else if (array.A[mid] > key)
            high = mid -1;
        else
            low = mid + 1;
    }
    return -1;  // unsuccessful
}

int main()
{
    struct Array A = {{4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43}, 15, 15};
    if (Binary_Search(A, 18) != -1)
        cout << "The index of the element we searched is: " << Binary_Search(A, 18) << endl;
    else
        cout << "The element does not exist in the array." << endl;
    return 0;
}
#include<iostream>
using namespace std;

class DEqueue
{
    private: 
        int front;
        int rear;
        int size;
        int* Q;
    public:
        DEqueue(int size);
        ~DEqueue();
        void display();
        void enqueueFront(int x);
        void enqueueRear(int x);
        int dequeueFront();
        int dequeueRear();
        bool isEmpty();
        bool isFull();
};

DEqueue::DEqueue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int [size];
}

DEqueue::~DEqueue()
{
    delete [] Q;
}

bool DEqueue::isEmpty()
{
    if(rear == front) return true;
    return false;
}

bool DEqueue::isFull()
{
    if(rear==size-1) return true;
    return false;
}

void DEqueue::enqueueFront(int x)
{
    if(front<=0) cout << "DEqueue Overflow" << endl;
    else
    {
        Q[front] = x;
        front --;
    }
}

void DEqueue::enqueueRear(int x)
{
    if(isFull()) cout << "DEqueue Overflow" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int DEqueue::dequeueFront()
{
    int x = -1;
    if(isEmpty()) cout << "DEqueue Underflow" << endl;
    else
    {
        x = Q[front];
        front++;
    }
    return x;
}

int DEqueue::dequeueRear()
{
    int x = -1;
    if(rear<=0) cout << "DEqueue Underflow" << endl;
    else
    {
        x = Q[rear];
        rear--;
    }
    return x;
}

void DEqueue::display()
{
    for(int i=front+1; i<=rear; i++)
    {
        cout << Q[i] << flush;
        if(i<rear) cout << " <- " << flush;
    }
    cout << endl;
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    DEqueue deq(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();
 
    cout << endl;
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();
 
    return 0;
}
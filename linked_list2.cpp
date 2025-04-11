#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
// Node *first = nullptr; Node *last = nullptr; cannot use global variable this time

void Display(struct Node *p)
{
    if(p!=nullptr)
    {
        cout << p->data;
        if(p->next != nullptr)
            cout << " -> ";
        Display(p->next);
    }
}

void Insert(Node* &head, int pos, int x)
{
    Node* t = new Node;
    t->data = x;
    t->next = nullptr;

    if(pos==0) // Insert before the head node
    {
        t->next = head;
        head = t;
    }
    else if(pos>0) // Insert at a given position
    {
        Node *p = head;
        for(int i=0; i<pos-1 && p; i++) p = p->next;
        if(p)
        {
            t->next = p->next;
            p->next = t;
        }
    else delete t;
    }
}

void InsertLast(Node* &head, Node* &last, int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = nullptr;
    if(head == nullptr) head = last = t;
    else
    {
        last ->next = t;
        last = t;
    }
}

void InsertInASortedLL(Node* &head, int x)
{
    Node* p = head;
    Node* q = nullptr;
    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }
    Node* t = new Node;
    t->data = x; t->next = p; 
    if(!q) head = t; // check if the node is smaller than the first one
    else q->next = t;
}

int Delete(Node* &head, int pos)
{
    Node* p = new Node;
    Node* q = new Node;
    int x = -1, i;
    if(pos == 1)
    {
        x = head->data;
        p = head;
        head = head->next;
        delete p;
    } 
    else
    {
        p = head;
        q = nullptr;
        for(i=0;i<pos-1 && p; i++)
        {
            q = p; p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}

int CheckIfSorted(Node* &head)
{
    int x = INT_MIN;
    Node* p = new Node;
    p = head;
    while(p)
    {
        if(p->data < x) return false;
        x = p->data; p = p->next;
    }
    return true;
}

void RemoveDuplicated(Node* &head)
{
    Node* p = new Node; Node* q = new Node;
    p = head;
    q = head->next;
    while(q)
    {
        if(p->data != q->data)
        {
            p = q; q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    int A[] = {8, 3, 9, 7, 6};
    Node* head1 = nullptr;
    Node* last1 = nullptr;
    for(int i=0; i<sizeof(A) / sizeof(A[0]); i++) InsertLast(head1, last1, A[i]);

    int B[] = {3, 7, 9, 15, 20};
    Node* head2 = nullptr;
    Node* last2 = nullptr;
    for(int i=0; i<sizeof(B) / sizeof(B[0]); i++) InsertLast(head2, last2, B[i]);
    

    Display(head1); cout << endl;

    Insert(head1, 4, 100);
    Display(head1); cout << endl;
    if(CheckIfSorted(head1)) cout << "The linked list is sorted." << endl;
    else cout << "The linked list is not sorted." << endl;

    InsertLast(head1, last1, 99);
    Display(head1); cout << endl;

    Delete(head1, 2);
    Display(head1); cout << endl;

    Insert(head1, 4, 100); Insert(head1, 4, 100); Insert(head1, 4, 100);
    Display(head1); cout << endl;
    RemoveDuplicated(head1);
    Display(head1);cout << endl;


    cout << endl;
    Display(head2); cout << endl;
    if(CheckIfSorted(head2)) cout << "The linked list is sorted." << endl;
    else cout << "The linked list is not sorted." << endl;

    InsertInASortedLL(head2, 2);
    Display(head2); cout << endl;

    InsertInASortedLL(head2, 18);
    Display(head2); cout << endl;

    return 0;
}
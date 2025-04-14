#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void Insert(Node** head, int x)
{
    Node* t = new Node();
    t->data = x;

    if(!*head) // null
    {
        t->next = t;
        t->prev = t;
        *head = t;
    }
    else
    {
        Node* tail = (*head)->prev;
        tail->next = t;
        t->prev = tail;
        t->next = *head;
        (*head)->prev = t;
    }
}

Node* Create(int arr[], int n)
{
    Node* head = nullptr;
    for(int i=0; i<n; i++) Insert(&head, arr[i]);
    return head;
}

void Display(Node* head)
{
    if(!head) 
    {
        cout<<"List is empty."<<endl;
        return;
    }
    Node* p=head;
    cout<<"Circular Doubly Linked List: ";
    do{
        cout << p->data << " ";
        p=p->next;
    }while(p!=head);
    cout << endl;
}

int main()
{
    int arr[] = {6, 9, 2, 7, 8};
    int n  = sizeof(arr)/sizeof(arr[0]);

    Node* head = Create(arr, n);
    Display(head);
    return 0;
}
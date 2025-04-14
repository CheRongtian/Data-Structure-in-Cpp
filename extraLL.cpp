#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

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

void FindMidNode(Node* head)
{
    Node* p; Node* q;
    p=head; q=head;
    while(q)
    {
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }
    cout << "The middle node is: " << p->data << endl;
}

int main()
{
    int A[] = {0, 6, 3, 9, 11, 4, 2};
    Node* head1 = nullptr; Node* last1 = nullptr;
    for(int i=0; i<sizeof(A) / sizeof(A[0]); i++) InsertLast(head1, last1, A[i]);
    Display(head1); cout<<endl;
    FindMidNode(head1); 
    return 0;
}
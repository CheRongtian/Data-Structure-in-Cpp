# include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
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

void Concentrate(Node* &head1, Node* &head2)
{
    if(!head1) head1 = head2;
    else
    {
        Node* p = head1;
        while(p->next) p = p->next;
        p->next = head2;
    }
    head2 = nullptr;
}

Node* Merging(Node* p, Node* q)
{
    Node* third = nullptr;
    Node* last = nullptr;

    if(p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = nullptr;
    }

    else
    {
        third = last = q;
        q = q->next;
        last->next = nullptr;
    }

    while(p!=nullptr && q!=nullptr)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }
    if(p!=nullptr)
    last->next = p;
    else last->next = q;

    return third;
}

int main()
{
    int A[] = {2, 9, 6, 8};
    Node* head1 = nullptr; Node* last1 = nullptr;
    for(int i=0; i<sizeof(A) / sizeof(A[0]); i++) InsertLast(head1, last1, A[i]);

    int B[] = {10, 4, 7};
    Node* head2 = nullptr;  Node* last2 = nullptr;
    for(int i=0; i<sizeof(B) / sizeof(B[0]); i++) InsertLast(head2, last2, B[i]);

    Display(head1); cout << endl; 
    Display(head2); cout << endl;
    Concentrate(head1, head2); Display(head1); cout << endl;
    cout << endl;

    int C[] = {2, 8, 10, 15};
    Node* head3 = nullptr; Node* last3 = nullptr;
    for(int i=0; i<sizeof(C) / sizeof(C[0]); i++) InsertLast(head3, last3, C[i]);

    int D[] = {4, 7, 12, 14};
    Node* head4 = nullptr;  Node* last4 = nullptr;
    for(int i=0; i<sizeof(D) / sizeof(D[0]); i++) InsertLast(head4, last4, D[i]);

    Display(head3); cout << endl; 
    Display(head4); cout << endl;
    Node* Merged = Merging(head3, head4); Display(Merged); cout << endl;

    return 0;
}
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node* create(int A[], int n)
{
    int i;
    Node *first, *t, *last, *loopTarget;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    int loopPos = 2;
    if(loopPos == 0) loopTarget = first;

    for(i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;

        if(i == loopPos) loopTarget = t;
    }
    last->next = loopTarget;
    return first;
}

Node* createCircular(int A[], int n)
{
    if (n == 0) return nullptr;

    Node* first = new Node{A[0], nullptr};
    Node* last = first;

    for (int i = 1; i < n; i++) {
        Node* t = new Node{A[i], nullptr};
        last->next = t;
        last = t;
    }

    last->next = first;  // 🔁 Make it circular

    return first;
}

bool isLoop(Node* first)
{
    if (first == nullptr) return false;

    Node* p, *q;
    p = q = first;
    do{
        p = p->next;
        q = q->next;
        q = (q!=nullptr) ? q->next:nullptr;
    }while(p && q && p!= q);
    return (p == q);
}

void Displaycirll(Node* head)
{
    Node* p = head;
    do{
        cout << p->data << " -> ";
        p = p->next;
    }while(p!=head);
    cout << "(back to " << head->data << ")" << endl;
}

void DisplayCirLL(Node* p)
{
    static int flag = 0;
    static Node* start = nullptr;

    if(flag == 0) {           // First call: record the starting node
        start = p;
        flag = 1;
    }
    
    cout << p->data << " -> " << flush;
    
    // If the next node is not the starting node, keep recursing.
    if(p->next != start)
        DisplayCirLL(p->next);
    else {
        cout << "(back to " << start->data << ")" << endl;
        // Reset the static variables so that subsequent calls work properly.
        flag = 0;
        start = nullptr;
    }
}

void Insert(int pos, int x, Node* head)
{
    Node* t; Node* p;
    int i;
    if(pos == 0)
    {
        t = new Node;
        t->data = x;
        if(head == nullptr)
        {
            head = t;
            head->next = head;
        }
        else
        {
            p=head;
            while(p->next!=head) p=p->next;
            p->next=t; t->next=head; head=t;
        }
    }
    else
    {
        p=head;
        for(i=0;i<pos-1;i++) p=p->next;
        t=new Node;
        t->data = x; t->next = p->next; p->next = t;
    }
}

int Delete(int pos, Node* head)
{
    Node* p; Node* q; int x;
    if(pos==1)
    {
        p=head;
        while(p->next!=head) p=p->next;
        x = head->data;
        if(p==head)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            p->next = head->next;
            delete head; head = p->next;
        }
    }
    else
    {
        p=head;
        for(int i=0;i<pos-1;i++) p=p->next;
        q = p->next;
        p->next = q->next; x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    
    int A[] = {8, 5, 4, 7, 3, 9};
    Node* head = create(A, 6);  // returns pointer to looped list
    cout << endl;
    if(isLoop(head)) cout << "A loop" << endl;
    else cout << "Not a loop" << endl;
    cout << endl;

    int B[] = {8, 3, 9, 6, 2};
    Node* head2 = createCircular(B, 5);
    Displaycirll(head2); cout << endl;
    DisplayCirLL(head2); cout << endl;
    Insert(4, 10, head2); DisplayCirLL(head2); cout << endl;
    Delete(4, head2); DisplayCirLL(head2); cout << endl; 

    return 0;
}
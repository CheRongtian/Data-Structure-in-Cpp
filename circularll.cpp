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

    return 0;
}
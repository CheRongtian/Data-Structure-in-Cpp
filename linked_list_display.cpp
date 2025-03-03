# include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    Node *head = new Node;

    Node *temp;
    Node *last;

    head->data = A[0];
    head->next = nullptr;
    last = head;

    // Create a Linked List
    for (int i=1; i<sizeof(A)/sizeof(A[0]); i++)
    {
        // Create a temporary Node
        temp = new Node;

        // Populate temporary Node
        temp->data = A[i];
        temp->next=nullptr;

        // Last's next is pointing to temp
        last->next=temp;
        last=temp;
    }

    // Display Linked List
    Node *p = head;

    while(p!=nullptr)
    {
        cout << p->data;
        if (p->next != nullptr) {
            cout << " -> ";   // The last Node should not be followed by a ->
        }
        p = p->next;
    }
    
    cout << endl;

    return 0;
}
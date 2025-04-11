# include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node* first = nullptr;

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

int CountNode(struct Node *p)
{
    int c = 0;
    while(p!=0)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Countnode(struct Node *p)
{
    if (p==0) return 0;
    else return Countnode(p->next)+1;
}

int Add(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int add (struct Node *p)
{
    if(p==0) return 0;
    else return add(p->next) + p->data;
}

int FindMax(struct Node *p)
{
    int max = -32786;
    while(p)
    {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Findmax(struct Node *p)
{
    int x=0;
    if(p==0) return -32786;
    else
    {
        x = Findmax(p->next);
        if(x > p->data) return x;
        else return p->data;
    }
}

int findmax(struct Node *p)
{
    int x = 0;
    if(p==0) return INT_MIN;
    x = findmax(p->next);
    return (x > p->data)? x:p->data; // another form
}

Node* Search(struct Node *p, int key)
{
    while(p!=nullptr)
    {
        if(key == p->data) return p;
        p = p->next;
    }
    return nullptr;
}

Node* search(struct Node *p, int key)
{
    if(p == nullptr) return nullptr;
    if(key == p->data) return p;
    else return search(p->next, key);
}

Node* Search2(Node* p, int key, int& position)
{
    position = 1;
    while (p != nullptr)
    {
        if (p->data == key)
            return p;
        p = p->next;
        position++;
    }
    position = -1;
    return nullptr;
}

Node* ImproveLinearSearch(Node *p, int key)
{
    Node *q = nullptr;
    while(p!=nullptr)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        return p;

        q = p;
        p = p->next;
        return nullptr;
    } 
}

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
    
    Display(head);
    cout << endl;

    cout <<"The node number is: "<< CountNode(head) << endl;
    cout <<"The node number is: "<< Countnode(head) << endl;
    cout <<"The sum of nodes is: "<< Add(head) << endl;
    cout <<"The sum of nodes is: "<< add(head) << endl;
    cout <<"The max node is: "<< FindMax(head) << endl;
    cout <<"The max node is: "<< Findmax(head) << endl;
    cout <<"The max node is: "<< findmax(head) << endl;
    
    int key=7;
    if(Search(head, key)) cout << "Found " << key << " in the linked list." << endl;
    else cout << key << " is not in the linked list" << endl;

    if(search(head, key)) cout << "Found " << key << " in the linked list." << endl;
    else cout << key << " is not in the linked list" << endl;

    int pos;
    if(Search2(head, key, pos))
       cout << "It is the " << pos << "th node. (Address: " << Search2(head, key, pos) << ")" << endl;
    
    if(ImproveLinearSearch(head, key)) cout << "Found " << key << " in the linked list." << endl;
    else cout << key << " is not in the linked list" << endl;
    return 0;
}
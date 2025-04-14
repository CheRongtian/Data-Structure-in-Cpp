# include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void Display(Node* head)
{
    Node* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Insert(int x, int pos, Node** head)
{
    Node* t = new Node(); 
    t->data = x;
    t->prev=nullptr;
    t->next=nullptr;

    if(pos == 1)
    {
        t->next = *head;
        if(*head!=nullptr) (*head)->prev = t;
        *head = t;
    }
    else
    {
        Node* p = *head;
        for(int i=1; i< pos-1&&p!=nullptr; i++) p = p->next;
        if(!p)
        {
            delete t;
            return;
        }
        t->next = p->next; t->prev = p;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}

Node* createDLL(int arr[], int n)
{
    Node* head = nullptr;
    for(int i = 0; i<n; i++) Insert(arr[i], i+1, &head);
    return head;
}

void Delete(int pos, Node* head)
{
    Node* p; int x;
    if(pos == 1)
    {
        p=head;
        head = head->next; x=p->data;
        delete p;
        if(head) head->prev = nullptr;
    }
    else
    {
        p=head;
        for(int i=0; i < pos-1; i++) p=p->next;
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        x=p->data;
        delete p;
    }
}

Node* Reverse(Node* head)
{
    Node* p = head;  
    Node* temp;
    while(p)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p=p->prev;
    }
    if(temp) head = temp->prev;

    return head;
}

int main()
{
    int arr[] = {6, 9, 3, 7, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the doubly linked list from the array
    Node* head = createDLL(arr, size);

    // Print the created list
    Display(head); cout << endl;
    Insert(10, 4, &head);  Display(head); cout << endl;
    Delete(4, head); Display(head); cout << endl;

    head = Reverse(head); Display(head); cout << endl;

    return 0;
}
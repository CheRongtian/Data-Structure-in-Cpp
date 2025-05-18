#include <iostream>
using namespace std;

class Node
{
    public:
        int coeff;
        int exp;
        Node *next;

        Node(int c, int e): coeff(c), exp(e), next(nullptr){}
};

class Polynomial
{
    private:
        Node *head;
    
    public:
        Polynomial()
        {
            head = nullptr;
        }

        ~Polynomial()
        {
            Node *p = head;
            while(p)
            {
                Node *temp = p;
                p = p->next;
                delete temp;
            }
        }

        void insertTerm(int coeff, int exp);

        Polynomial operator+(Polynomial &p);
        friend istream &operator >> (istream &is, Polynomial &p);
        friend ostream &operator << (ostream &os, Polynomial &p);
};

void Polynomial::insertTerm(int coeff, int exp)
{
    Node *t = new Node(coeff, exp);
    if(!head || exp > head->exp)
    {
        t->next = head;
        head = t;
    }
    else
    {
        Node *p = head;
        Node *q = nullptr;

        while(p && p->exp >exp)
        {
            q = p;
            p = p->next; 
        }
        
        if(p && p->exp == exp)
        {
            p->coeff += coeff;
            delete t;
        }
        else
        {
            t->next = p;
            if(q) q->next = t;
            else head = t;
        }
    }
}

istream &operator>>(istream &is, Polynomial &p)
{
    int n;
    cout << "Number of terms?";
    is >> n;
    cout << "Enter terms (coefficient and exponent): "<<endl;
    for(int i = 0; i<n; i++)
    {
        int c, e;
        is >> c >> e;
        p.insertTerm(c,e);
    }
    return is;
}

ostream &operator<<(ostream &os, Polynomial &p)
{
    Node *temp = p.head;
    while(temp)
    {
        os << temp->coeff << "x^" << temp->exp;
        if(temp->next) os << " + ";
        temp = temp->next;
    }
    os << endl;
    return os;
}

Polynomial Polynomial::operator+(Polynomial &p)
{
    Polynomial result;
    Node *a = this->head;
    Node *b = p.head;

    while(a && b)
    {
        if(a->exp > b->exp)
        {
            result.insertTerm(a->coeff, a->exp);
            a = a->next;
        }
        
        else if(a->exp < b->exp)
        {
            result.insertTerm(b->coeff, b->exp);
            b = b->next;
        }
        
        else
        {
            result.insertTerm(a->coeff + b->coeff, a->exp);
            a = a->next;
            b = b->next;
        }
    }

    while(a)
    {
        result.insertTerm(a->coeff, a->exp);
        a = a->next;
    }

    while(b)
    {
        result.insertTerm(b->coeff, b->exp);
        b = b->next;
    }

    return result;
}
int main()
{
    Polynomial p1, p2;

    cin >> p1;
    cin >> p2;

    Polynomial p3 = p1 + p2;

    cout << "First Polynomial: ";
    cout << p1;

    cout << "Second Polynomial: ";
    cout << p2;

    cout << "Sum Polynomial: ";
    cout << p3;
    
    return 0;
}
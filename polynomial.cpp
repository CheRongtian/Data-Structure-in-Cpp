#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Polynomial
{
private:
    int n;
    Term *terms;

public:
    Polynomial(int n = 0)
    {
        this->n = n;
        terms = new Term[n];
    }

    ~Polynomial()
    {
        delete[] terms;
    }

    friend istream &operator>>(istream &is, Polynomial &p);
    friend ostream &operator<<(ostream &os, Polynomial &p);
    Polynomial operator+(Polynomial &p);
};

istream &operator>>(istream &is, Polynomial &p)
{
    cout << "Number of terms? ";
    is >> p.n;
    p.terms = new Term[p.n];

    cout << "Enter terms (coefficient and exponent):\n";
    for (int i = 0; i < p.n; i++)
    {
        is >> p.terms[i].coeff >> p.terms[i].exp;
    }
    return is;
}

ostream &operator<<(ostream &os, Polynomial &p)
{
    for (int i = 0; i < p.n; i++)
    {
        os << p.terms[i].coeff << "x^" << p.terms[i].exp;
        if (i != p.n - 1)
            os << " + ";
    }
    os << endl;
    return os;
}

Polynomial Polynomial::operator+(Polynomial &p)
{
    Polynomial *sum = new Polynomial(n + p.n);
    int i = 0, j = 0, k = 0;

    while (i < n && j < p.n)
    {
        if (terms[i].exp > p.terms[j].exp)
            sum->terms[k++] = terms[i++];
        else if (terms[i].exp < p.terms[j].exp)
            sum->terms[k++] = p.terms[j++];
        else
        {
            sum->terms[k].exp = terms[i].exp;
            sum->terms[k++].coeff = terms[i++].coeff + p.terms[j++].coeff;
        }
    }

    while (i < n)
        sum->terms[k++] = terms[i++];
    while (j < p.n)
        sum->terms[k++] = p.terms[j++];

    sum->n = k;
    return *sum;
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

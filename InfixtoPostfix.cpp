#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(char x) {
        Node* t = new Node;
        if (!t) {
            cout << "Stack Overflow" << endl;
            return;
        }
        t->data = x;
        t->next = top;
        top = t;
    }

    char pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* t = top;
        char x = t->data;
        top = top->next;
        delete t;
        return x;
    }

    char peek() {
        return (top) ? top->data : '\0';
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int isOperand(char x) {
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

string InfixToPostfix(const string& infix) {
    Stack st;
    string postfix;
    st.push('#');  // dummy bottom

    for (char token : infix) {
        if (isOperand(token)) {
            postfix += token;
        } else {
            while (precedence(token) <= precedence(st.peek())) {
                postfix += st.pop();
            }
            st.push(token);
        }
    }

    while (!st.isEmpty() && st.peek() != '#') {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*c-d/e";
    string postfix = InfixToPostfix(infix);

    cout << "Postfix: " << postfix << endl;
    return 0;
}

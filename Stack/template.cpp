#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
public:
    T *arr;
    int n;
    int sp;

public:
    Stack(int n)
    {
        arr = new T[n];
        this->n = n;
        sp = -1;
    }
    void push(T);
    void pop();
    T peek();
    bool isEmpty();
    ~Stack()
    {
        // cout << "Destructor called" << endl;
        delete[] arr;
    }
};

template <class T>
void Stack<T>::push(T data)
{
    if (sp == n - 1)
    {
        cout << "OverFlow" << endl;
        return;
    }
    sp++;
    arr[sp] = data;
}

template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "UnderFlow" << endl;
        return;
    }
    sp--;
}
template <class T>
bool Stack<T>::isEmpty()
{
    return sp == -1;
}
template <class T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        cout << "Stack UnderFlow" << endl;
        return T(INT_MIN);
    }
    return arr[sp];
}

int precedence(char op) {
    if(op == '^') { return 3; }
    else if(op == '*' || op == '/') { return 2; }
    else if(op == '+' || op == '-') { return 1; }
    else return -1;
}

string infix_to_postfix(string exp) {
    Stack<char> st(exp.size());
    string temp = "";
    for(int i = 0; i < exp.size(); i++) {
        char ch = exp[i];
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
            temp.push_back(ch);
        }
        else if(ch == '(') {
            st.push('(');
        }else if(ch == ')') {
            while(st.peek() != '(') {
                temp.push_back(st.peek());
                st.pop();
            }
            st.pop();
        }else {
            while(!st.isEmpty() && precedence(ch) <= precedence(st.peek())) {
                temp.push_back(st.peek());
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        temp.push_back(st.peek());
        st.pop();
    }
    return temp;
}    


int main()
{
    // Stack<float> st(5);
    // st.push(10.0);
    // st.push(20.1);
    // st.push(30.6);
    // while (!st.isEmpty())
    // {
    //     cout << st.peek() << endl;
    //     st.pop();
    // }

    string exp = "A+(B*C)";

    string ans = infix_to_postfix(exp);
    cout << ans; 

    return 0;
}
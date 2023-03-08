#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    int size;

    Stack()
    {
        top = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int data)
    {
        Node *newTop = new Node(data);
        if (top == NULL)
        {
            top = newTop;
            size++;
            return;
        }
        newTop->next = top;
        top = newTop;
        size++;
    }

    int pop()
    {
        if (top == NULL)
        {
            return INT_MIN;
        }
        int data = top->data;
        top = top->next;
        size--;
        return data;
    }

    int peek()
    {
        if (top == NULL)
        {
            return INT_MIN;
        }
        return top->data;
    }
};
int main()
{
    Stack* st = new Stack();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->push(6);

    while (!st->isEmpty()) {
        cout << st->peek() << " ";
        st->pop();        
    }
    
    return 0;
}
#include <iostream>
using namespace std;
// Deque Implemenation Using Doubly linked list
class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = this->prev = NULL;
    }
};

class Deque
{
    Node *front;
    Node *rear;
    int size;

public:
    Deque()
    {
        this->front = NULL;
        this->rear = NULL;
        this->size = 0;
    }

    void pushFront(int);
    void pushBack(int);
    int popFront();
    int popBack();
    int peekFront();
    int peekBack();
    int len();
    void print();
};

int Deque::len()
{
    return size;
}

void Deque::pushFront(int data)
{
    Node *newNode = new Node(data);
    if (front == NULL)
    {
        front = rear = newNode;
        size++;
        return;
    }
    newNode->next = front;
    front->prev = newNode;
    front = newNode;
    size++;
}

void Deque::pushBack(int data)
{
    Node *newNode = new Node(data);
    if (rear == NULL)
    {
        rear = front = newNode;
        size++;
        return;
    }
    newNode->prev = rear;
    rear->next = newNode;
    rear = newNode;
    size++;
}

int Deque::popFront()
{
    if (front == NULL)
    {
        cout << "undeflow"
             << " " << endl;
        return INT_MIN;
    }
    int item = front->data;
    Node *todel = front;
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    else
    {
        front->prev = NULL;
    }
    delete todel;
    size--;
    return item;
}

int Deque::popBack()
{
    if (rear == NULL)
    {
        cout << "undeflow"
             << " " << endl;
        return INT_MIN;
    }
    int item = rear->data;
    Node *todel = rear;
    rear = rear->prev;
    if (rear == NULL)
    {
        front = NULL;
    }
    else
    {
        rear->next = NULL;
    }
    delete todel;
    size--;
    return item;
}
int Deque::peekFront()
{
    if (front == NULL)
    {
        cout << "undeflow"
             << " " << endl;
        return INT_MIN;
    }
    return front->data;
}
int Deque::peekBack()
{
    if (rear == NULL)
    {
        cout << "undeflow"
             << " " << endl;
        return INT_MIN;
    }
    return rear->data;
}

void Deque::print()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Deque *dq = new Deque();
    dq->pushFront(5);
    dq->pushFront(10);

    dq->pushBack(20);
    dq->pushBack(40);

    dq->print();
    cout << "Size of Deque = " << dq->len();
    return 0;
}
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
    // Functions to add data in front or rear
    void pushFront(int);
    void pushBack(int);

    // Functions to delete data from front or rear
    int popFront();
    int popBack();

    // Functions to get data from front or rear
    int peekFront();
    int peekBack();

    // Function to get size of Deque
    int len();

    // Function to print elements of Deque
    void print();
};

int Deque::len()
{
    return size;
}

void Deque::pushFront(int data)
{
    Node *newNode = new Node(data);
    // If Queue is empty,then make newNode as front and rear
    if (front == NULL)
    {
        front = rear = newNode;
        size++;
        return;
    }
    // else perform insert at head operation
    newNode->next = front;
    front->prev = newNode;
    // Make new Node as head(front) and increase the size by 1
    front = newNode;
    size++;
}

void Deque::pushBack(int data)
{
    Node *newNode = new Node(data);
    // If Queue is empty,then make newNode as front and rear
    if (rear == NULL)
    {
        rear = front = newNode;
        size++;
        return;
    }
    // else perform insert at tail operation
    newNode->prev = rear;
    rear->next = newNode;
    // Make new Node as tail(rear) and increase the size by 1
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
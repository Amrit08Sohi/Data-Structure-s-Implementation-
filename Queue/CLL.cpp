#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;

    public:
        Node(int data) {
            this->data = data;
        }   
};

class CQueue {
    public:
        Node* front;
        Node* rear;
        int size;

        CQueue() {
            this->front = NULL;
            this->rear = NULL;
            this->size = 0;
        }

        void add(int);
        int del();
        int peek();
        void print();     
};

void CQueue::add(int data) {
    Node* newNode = new Node(data);
    if(front == NULL) {
        front = rear = newNode;
        newNode->next = newNode;
        return;
    }
    rear->next = newNode;
    newNode->next = front;
    rear = newNode;
}

int CQueue::del() {
    if(front == NULL) {
        cout << "underflow" << endl;
        return INT_MIN;
    }
    if(front == rear) {
        int item = front->data;
        front = rear = NULL;
        return item;
    }

    int item = front->data;
    Node* todel = front;
    front = front->next;
    rear->next = front;
    delete todel;
    return item; 
}

int CQueue::peek() {
    if(front == NULL) {
        cout << "underflow" << endl;
        return INT_MIN;
    }
    return front->data;
}

void CQueue::print() {
    Node* temp = front;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp!=front);
    cout << endl;
}
int main()
{
    CQueue* q = new CQueue();
    q->add(10);
    q->add(20);
    q->add(30);
    q->print();
    return 0;
}
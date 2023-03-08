#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node* next;

    public:
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }   
};

class Queue {
    public:
        Node* front;
        Node* rear;
        int size;

        Queue() {
            this->front = NULL;
            this->rear = NULL;
            this->size = 0;
        }

        void add(int);
        int del();
        int peek();
        void print();     
};

void Queue::add(int data) {
    Node* newNode = new Node(data);
    if(front == nullptr) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int Queue::del() {
    if(front == NULL) {
        cout << "underflow";
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
    delete todel;
    return item;
}

int Queue::peek() {
    if(front == NULL) {
        cout << "underflow";
        return INT_MIN;
    }
    return front->data;
}

void Queue::print() {
    Node* temp = front;
    while(temp!=NULL) {
        cout << temp->data << " "; 
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Queue* q = new Queue();
    q->add(10);
    cout << q->del() << endl;
    cout << q->front << "  " << q->rear << "  " << endl;
    q->print();
    return 0;
}
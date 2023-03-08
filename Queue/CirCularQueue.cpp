#include<iostream>
using namespace std;
class Cqueue {
    private:
        int* arr;
        int rear,front;
        int size;
        int n;
    public:
        Cqueue(int n) {
            this->n = n;
            arr = new int[n];
            this->size = 0;
            this->rear = this->front = -1;
        }

        void add(int);
        int remove();
        int peek();
        void print();
        ~Cqueue() {
            delete[] arr;
        }

};
 
void Cqueue::print() {
    for(int i = front; i <= rear; i++) {
        cout << arr[i%n] << " ";
    }
    cout << endl;
}

void Cqueue::add(int data) {
    if(front == 0 && rear == n-1 && front == rear + 1) {
        cout << "Overflow" << endl;
        return;
    }
    if(front == -1) {
        front = 0;
        rear = 0;
    }else if(rear == n-1) {
        rear = 0;
    }else {
        rear++;
    }
    arr[rear] = data;
}



int Cqueue::remove() {
    if(front == -1) {
        cout << "underflow" << endl;
        return INT_MIN;
    }
    int delItem = arr[front];
    if(front == rear) {
        front = -1;
        rear = -1;
    }else if(front == n-1) {
        front = 0;
    } else {
        front++;
    }

    return delItem;
}

int Cqueue::peek() {
    if(front == -1) {
        cout << "underflow" << endl;
        return INT_MIN;
    }
    return arr[front];
}
int main()
{
    Cqueue* q = new Cqueue(4);

    
    return 0;
}
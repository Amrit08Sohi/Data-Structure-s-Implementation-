#include<iostream>
using namespace std;
class Queue{
    private:
        int *arr;
        int n;
        int rear;
        int size;
    public:
        Queue(int n) {
            this->n = n;
            arr = new int[n];
            this->rear = -1;
            this->size = 0;
        }

        void add(int);
        int remove();
        void print();
        
        ~Queue() {
            delete[] arr;
        }
};

void Queue::add(int data) {
    if(rear == n-1) {
        cout << "Overflow";
        return;
    }
    rear++;
    size++;
    arr[rear] = data;
}

int Queue::remove() {
    if(rear == -1) {
        cout << "underflow";
        return INT_MIN;
    }

    int item = arr[0];

    for(int i = 0; i < rear; i++) {
        arr[i] = arr[i+1];
    } 
    rear--;
    size--;
    return item;
}

void Queue::print() {
    cout << "Queue Elements" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the size of Queue" << endl;
    cin >> n;
    int data;
    Queue* q = new Queue(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Data" << endl;
        cin >> data;
        q->add(data);
    }
    q->print();
    
    
    

    return 0;
}
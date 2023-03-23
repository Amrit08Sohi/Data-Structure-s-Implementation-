#include<bits/stdc++.h>
using namespace std;
// Implementing MIN HEAP
class Heap{
    public:
        vector<int> arr;

        void add(int);
        void heapify(int i);
        int remove();
        int peek();
        bool isEmpty();
};

void Heap::add(int data) {
    // Step 1: Add at Last
    arr.push_back(data);

    // Fix the vector to maintain min heap
    int childIdx = arr.size()-1;
    int parIdx = (childIdx-1)/2;

    while(arr[childIdx] < arr[parIdx]) {
        swap(arr[childIdx],arr[parIdx]);
        childIdx = parIdx;
        parIdx = (childIdx-1)/2;
    } 
}
void Heap::heapify(int i) {
    int left = 2*i+1;
    int right = 2*i+2;
    int minIdx = i;

    if(left < arr.size() && arr[left] < arr[minIdx]) {
        minIdx = left;
    }
    if(right < arr.size() && arr[right] < arr[minIdx]) {
        minIdx = right;
    }

    if(minIdx != i) {
        swap(arr[i],arr[minIdx]);
        heapify(minIdx);
    }
}

int Heap::remove() {
    // Save the data that we return
    int data = arr[0];
    // Step1 : Swap first and last index
    swap(arr[0],arr[arr.size()-1]);
    // Step 2 : Remove last
    arr.pop_back();

    // Step3 : fix Heap
    heapify(0);
    return data;
}

int Heap::peek(){
    return arr[0];
}
bool Heap::isEmpty() {
    return arr.size() == 0;
}
int main()
{
    Heap* pq = new Heap();
    pq->add(3);
    pq->add(4);
    pq->add(1);
    pq->add(5);

    while (!pq->isEmpty())
    {
        cout << pq->peek() << " ";
        pq->remove();
    }
    

    return 0;
}
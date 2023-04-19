#include<bits/stdc++.h>
using namespace std;

void heapify(int *arr,int root,int size) {
    int left = 2*root+1;
    int right = 2*root+2;
    int maxIdx = root;

    if(left < size && arr[left] > arr[maxIdx]) {
        maxIdx = left;
    }
    if(right < size && arr[right] > arr[maxIdx]) {
        maxIdx = right;
    }

    if(maxIdx != root) {
        swap(arr[maxIdx],arr[root]);

        heapify(arr,maxIdx,size);
    }
}


void heapSort(int *arr,int n) {
    // Step 1 : Building MaxHeap to sort in ascending order
    for(int i = n/2; i >= 0; i--) {
        heapify(arr,i,n);
        cout << "Pass" << endl;
        for(int i = 0; i < n; i++ ) {
            cout << arr[i] << " " ;
        }
        cout << endl;
    }   

    //Step 2 : Swap first and last element
    for(int i = n-1; i > 0; i--) {
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
        cout << "heapify" << endl;
        for(int i = 0; i < n; i++ ) {
            cout << arr[i] << " " ;
        }
        cout << endl;
    }
}
/*
10 20 40 50 30


pass1 :  10 20 40 50 30
pass2 :  10 50 40 20 30
pass3 :  50 10 40 20 30
pass3Sub:50 30 40 20 10
         10 30 40 20 50
         40 30 10 20 50
          
         20 30 10 40 50
         30 20 10 40 50

         10 20 30 40 50   
          
         20 10 30 40 50
 
         10 20 30 40 50




            50
           /  \
         30    40
       /   \
      20   10    
*/

int main()
{
    int arr[] = {10,20,40,50,30};
    int n = 5;
    cout << "Before Sorting" << endl;
    for(int i : arr) {
        cout << i << " ";
    } 
    cout << endl;

    heapSort(arr,n);

    cout << "After Sorting" << endl;
    for(int i : arr) {
        cout << i << " ";
    } 
    cout << endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void selection_sort(int *arr,int n) {
    // Loop for number of passes
    for(int i = 0; i < n-1; i++) {
        int minPos = i;
        // Loop for sorting
        for(int j = i+1; j < n; j++) {
            // Comparing ith element with all elements
            if(arr[j] < arr[minPos]) {
                minPos = j;
            } 
        }
        // Swap
        if(minPos != i) {
            swap(arr[i],arr[minPos]);
        }
    }
}
int main()
{
    int arr[] = {5,2,1,3,4,9};
    int n = 6;
    
    cout << "Before Sorting" << endl;
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    selection_sort(arr,n);
    cout << "After Sorting" << endl;
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}
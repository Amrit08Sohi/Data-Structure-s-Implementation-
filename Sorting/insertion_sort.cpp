#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && curr < arr[prev]) {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}
int main()
{
    int arr[] = {5,2,1,3,4};
    int n = 5;
    cout << "Before Sorting" << endl;
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;
    insertion_sort(arr,n);
    cout << "After Sorting" << endl;
    for(int i : arr) {
        cout << i << " ";
    }
    return 0;
}
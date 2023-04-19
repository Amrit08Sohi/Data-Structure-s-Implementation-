#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int st,int mid,int end) {
    int temp[end-st+1];
    int i = st,j = mid+1;
    int k = 0;
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i<=mid){
        temp[k++] = arr[i++];
    }
    while (j<=end){
        temp[k++] = arr[j++];
    }

    for(i = st,k = 0; k < end-st+1;) {
        arr[i++] = temp[k++];
    }
}  

void mergeSort(int arr[],int st,int end) {
    if(st < end) {
        int mid = (st + end)/2;

        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
}
int main()
{
    int n;
    cout << "Enter number of elements" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements" << endl;
    for(auto &i : arr){
        cin >> i;
    }

    mergeSort(arr,0,n-1);
    cout << "After Sorting" << endl;

    for(int ele : arr){
        cout << ele << ' ';
    }

    return 0;
    return 0;
}
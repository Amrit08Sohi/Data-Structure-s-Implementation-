#include<bits/stdc++.h>
using namespace std;
int lower[20];
int upper[20];
int top = -1;
int partition(int arr[],int n,int st,int end){
    int left = st;
    int right = end;
    int pivot = end;

    while (n>=1)
    {
        while(arr[left] < arr[pivot] && left != pivot) {
            left++;
        }
        if(pivot == left) {
            return pivot;
        }
        if(arr[left] > arr[pivot]) {
            swap(arr[left], arr[pivot]);
            pivot = left;
        }

        while(arr[right] > arr[pivot] && right != pivot) {
            right--;
        }
        if(pivot == right) {
            return pivot;
        }
        if(arr[right] < arr[pivot]) {
            swap(arr[right], arr[pivot]);
            pivot = right;
        }
        n--;
    }
    return -1;
}

void quick_sort(int arr[],int n){
    int st,end,pivot;
    if(n>=2){
        top++;
        lower[top] = 0;
        upper[top] = n-1;
    }

    while(top != -1) {
        st = lower[top], end = upper[top];
        top--;
        pivot = partition(arr,n,st,end);

        if(st <= pivot-2) {
            top++;
            lower[top] = st;
            upper[top] = pivot - 1;
        }

        if(end >= pivot+2){
            top++;
            lower[top] = pivot+1;
            upper[top] = end;
        }
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

    quick_sort(arr,n);
    cout << "After Sorting" << endl;

    for(int ele : arr){
        cout << ele << ' ';
    }

    return 0;
}
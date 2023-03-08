#include<iostream>
using namespace std;
void printArray(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void deletion(int *arr,int n,int key){
    // find position of key
    int pos = -1;
    for(int i = 0; i < n; i++){
        if(*(arr+i) == key){
            pos = i;
            break;
        }
    }
    // deletion
    for(int i = pos; i < n-1; i++){
        arr[i] = arr[i+1];
    }
}

//  idx : 0 1 2 3 4 5
//  ele : 1 2 3 4 5 6
void insertion(int *arr,int n,int key,int idx){
    for(int i = n-1; i >= idx; i--){ // for 1 base change condition i >= idx-1 
        arr[i+1] = arr[i];
    }
    arr[idx] = key;  
}

void insertInSorted(int *arr,int n,int key){ // case : ascending order
    if(arr[0] >= key){
        insertion(arr,n,key,0);
        return;
    }else if(arr[n-1] <= key){
        insertion(arr,n,key,n );
        return;
    }

    int pos = -1;
    for(int i = 1; i < n; i++){
        if(arr[i-1] <= key && arr[i] >= key) {
            pos = i;
            break;
        }
    }
    insertion(arr,n,key,pos);
}
int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements" << endl;
    for(auto &i : arr){
        cin >> i;
    }

    int choice;
    cout << "Enter 1 for print array elements" << endl
         << "Enter 2 for delete element" << endl
         << "Enter 3 for insert element" << endl
         << "Enter 4 for insert element in sorted array" << endl;
    char ct = 'y';
    while (ct=='y')
    {
        cout << "Ente choice" << endl;
        cin >> choice;
        switch(choice){
            case 1: 
                printArray(arr,n);
                break;;
            case 2: 
                int key;
                cout << "Enter the element that you want to delete" << endl;
                cin >> key;
                deletion(arr,n,key);
                n--;
                break;     
            case 3:
                int ele;
                cout << "Enter the element that you want to insert" << endl;
                cin >> ele;
                int idx;
                cout << "Enter the index where you want to insert" << endl;
                cin >> idx;
                insertion(arr,n,ele,idx);
                n++;
                break;
            case 4:
                cout << "Enter the element that you want to insert" << endl;
                cin >> ele;
                insertInSorted(arr,n,ele);
                n++;
                break;
            default:
                cout << "Invalid" << endl;
                break;        
        }
        cout << "Wnt to continue" << endl;
        cin >> ct;
    }

    return 0;
}
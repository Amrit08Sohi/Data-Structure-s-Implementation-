#include<bits/stdc++.h>
using namespace std;
int* _union(int *a,int n,int *b,int m) {
    int *union_ = new int[n+m];
    int k = 0;
    for(int i = 0; i < n; i++) {
        union_[k++] = a[i];
    }
    for(int i = 0; i < m; i++) {
        int curr = b[i];
        bool flag = false;
        for(int j = 0; j < n; j++) {
            if(curr == union_[j]) {
                flag = true;
                break;
            }
        }
        if(!flag) {
            union_[k++] = curr;
        }
    }
    return union_;
}
int* _intersection(int *a,int n,int *b,int m) {
    int mini = n <= m ? n : m;
    int *intersection = new int[n];
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] == b[j]) {
                intersection[k++] = a[i];
                break;
            }
        }
    }
    return intersection;
}

// Using Sorting and Binary Search
int binary_search(int *a,int n,int key) {
    int st = 0, end= n-1;
    while(st <= end) {
        int mid = (st+end)/2;
        if(a[mid] == key) {
            return mid;
        } else if(a[mid] > key) {
            end = mid-1;
        } else {
            st = mid+1;
        }
    }
    return -1;
}
void __union(int* a, int n, int* b, int m) {
    if(n > m) {
        int *temp = a;
        a = b;
        b = temp;

        int t = n;
        n = m;
        m = t;
    }

    sort(a,a+n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    for(int i = 0; i < m; i++) {
        if(binary_search(a,n,b[i]) == -1) {
            cout << b[i] << " ";
        } 
    }
}

void __intersection(int* a, int n, int* b, int m) {
    if(n > m) {
        int *temp = a;
        a = b;
        b = temp;

        int t = n;
        n = m;
        m = t;
    }

    sort(a,a+n);
    for(int i = 0; i < m; i++) {
        if(binary_search(a,n,b[i]) != -1) {
            cout << b[i] << " ";
        }
    }
}


// Optimal solution handling Duplicates

void is_next_same(int &x,int *arr,int len) {
    do
    {
        x++;
    } while (x < len and arr[x-1] == arr[x]);
    
}
void __optimal_union(int* a, int n, int* b, int m) {
    sort(a,a+n);
    sort(b,b+m);
    int i = 0, j = 0;
    while(i < n and j < m) {
        if(a[i] < b[j]) {
            cout << a[i] << " ";
            is_next_same(i,a,n);
        } else if(a[i] > b[j]) {
            cout << b[j] << " "; 
            is_next_same(j,b,m);
        } else {
            cout << a[i] << " ";
            is_next_same(i,a,n);
            is_next_same(j,b,m);
        }
    }
    while(i < n) {
        cout << a[i] << " ";
        is_next_same(i,a,n);
    }
    while(j < m) {
        cout << b[j] << " ";
        is_next_same(j,b,m);
    }
}

void __optimal_intersection(int* a, int n, int* b, int m) {
    int i = 0, j =0;
    while(i < n and j < m) {
        if(i > 0 and a[i] == a[i-1]) {
            i++;
            continue;
        }
        if(a[i] < b[j]) {
            i++;
        } else if(a[i] > b[j]) {
            j++;
        } else {
            cout << b[j] << " ";
            i++;
            j++;
        }
    }
}
int main()
{
    int a[] = {4,3,2,1,4};
    int b[] = {5,4,6,3,4,1,2};
    int *union_ = _union(a,5,b,7);
    cout << "UNION" << endl;
    for(int *p = union_; *p; ++p) {
        cout << *p << " ";
    }
    cout << endl;
    cout << "Intersection" << endl;
    int *intersect_ = _intersection(a,5,b,7);
    for(int *p = intersect_; *p; ++p) {
        cout << *p << " ";
    }
    // cout << endl;
    // __optimal_union(a,5,b,7);
    // cout << endl;
    // __optimal_intersection(a,5,b,7);
    // cout << endl;
    // __union(a,4,b,7);
    // cout << endl;
    // __intersection(a,4,b,7);

    delete []union_;
    delete []intersect_;
    return 0;
}
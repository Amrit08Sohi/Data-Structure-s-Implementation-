#include<iostream>
using namespace std;
class Array{
    private:
        int n;
        int *a;
    public:
        Array(int n){
            this->n = n;
            a = new int[n];
    }

    public:
        void insert(Array arr,int key,int idx){
            for(int i = n-1; i >= idx; i--){
                arr.a[i+1] = arr.a[i];
            }
            arr.a[idx] = key;
            n++;
        }

        void print(Array arr){
            for(int i = 0; i < n; i++){
                cout << arr.a[i] << " "; 
            }
        }

        void input(Array arr){
            cout << "Enter " << n << " elements" << endl;
            for(int i = 0; i < n; i++){
                cin >> arr.a[i];
            }
        }
};
int main()
{
    Array a1(4);
    a1.input(a1);
    a1.print(a1);
    a1.insert(a1,20,3);
    a1.print(a1);
    return 0;
}
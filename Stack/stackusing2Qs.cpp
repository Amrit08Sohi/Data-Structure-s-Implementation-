#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
        queue<int> q1;
        queue<int> q2;

        bool isEmpty() {
            return q1.empty() && q2.empty();
        }

        void push(int data) {
            if(!q1.empty()) {
                q1.push(data);
            }else{
                q2.push(data);
            }
        }

        int pop() {
            if(isEmpty()) {
                return INT_MIN;
            }

            int top;

            if(!q1.empty()) {
                while(!q1.empty()){
                    top = q1.front();
                    q1.pop();
                    if(q1.empty()) {
                        break;
                    }
                    q2.push(top);
                }
            } else {
                while(!q2.empty()){
                    top = q2.front();
                    q2.pop();
                    if(q2.empty()) {
                        break;
                    }
                    q1.push(top);
                }
            }
            return top;
        }
};
int main()
{
    Stack st;
    st.push(10);
    st.pop();
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();

    while(!st.isEmpty()) {
        cout << st.pop() << " ";
    }
    return 0;
}
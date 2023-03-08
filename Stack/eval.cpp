#include<bits/stdc++.h>
using namespace std;
int helper(string exp){
    stack<int> st;

    for(char ch : exp){
        // '0'-'9' = 48-57
        if(ch >= '0' && ch <= '9'){
            st.push(ch - '0');
        }else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            if(ch == '+'){
                st.push(op2 + op1);
                // cout << st.top() << endl;
            }else if(ch == '*'){
                st.push(op2 * op1);
                // cout << st.top() << endl;
            }else if(ch == '-'){
                st.push(op2 - op1);
                // cout << st.top() << endl;
            }else if(ch == '/'){
                st.push(op2/op1);
            }
        }
    }
    int res = st.top();
    st.pop();
    return res;
}
int main()
{
    // string exp = "123+*8-";
    string exp = "231*+9-";
    cout << helper(exp) << endl;
    return 0;
}
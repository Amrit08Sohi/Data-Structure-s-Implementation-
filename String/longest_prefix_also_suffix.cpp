#include<bits/stdc++.h>
using namespace std;

// Brute force
string _longestPrefixSuffix(string &str){ // O(N)*O(N+N)
    int n = str.size();
    for(int i = n-2; i >= 0; i--) {
        string prefix = str.substr(0,i+1); // 0..n-1
        string suffix = str.substr(n-i-1); // 1--n
        if(prefix == suffix) {
            return prefix;
        }
    }
    return "";
} 

string substring(string &str,int i, int cnt) {
    string ans;
    while(cnt--) {
        ans.push_back(str[i]);
        i++;
    }
    return ans;
}
string longestPrefixSuffix(string &str){ // O(N)
    int n = str.size();
    vector<int> lps(n,0);
    int i = 1, j = 0;
    while(i < n) {
        if(str[i] == str[j]) {
            j++;
            lps[i] = j;
            i++;
        } else if(j!=0) {
            j = lps[j-1];
        } else {
            lps[i] = 0; // by deafault all values in lps are 0
            i++;
        }
    }
    return lps[n-1] == 0 ? "" : substring(str,0,lps[n-1]);
}


int main()
{
    string str = "ababcdabab";
    cout << longestPrefixSuffix(str);
    return 0;
}
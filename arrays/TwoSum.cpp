#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    sort(arr.begin(),arr.end());
    int i = 0, j = n-1;
    vector<pair<int,int>> ans;
    while(i < j) {
        if(arr[i] + arr[j] == target) {
            ans.push_back({arr[i],arr[j]});
            i++;
            j--;
        } else if(arr[i] + arr[j] > target) {
            j--;
        } else {
            i++;
        }
    }
    if(ans.empty()) {
        return {{-1,-1}};
    }
    return ans;
}
vector<pair<int,int>> _twoSum(vector<int>& arr, int target, int n)
{
    vector<pair<int,int>> ans;
    map<int,int> mp;
    for(int ele : arr) {
        int diff = target-ele;
        if(mp.find(diff) != mp.end()) {
            ans.push_back({diff,ele});
            mp[diff]--;
            if(mp[diff] == 0) {
                mp.erase(diff);
            }
        } else {
            mp[ele]++;
        }
    }
    if(ans.empty()) {
        return {{-1,-1}};
    }
    return ans;
}


int main()
{
    // vector<int> arr = {1, 2, 2, 1, 2, 1};
    // int target = 3;
    // vector<int> arr = {1, 0, 0, 1, 1};
    // int target = 2;
    vector<int> arr = {-9, 3, -2, 8 ,-3 ,4 };
    int target = 16;
    vector<pair<int,int>> ans = _twoSum(arr,target,arr.size());
    for(auto p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
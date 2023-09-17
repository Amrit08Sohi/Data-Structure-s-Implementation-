#include<bits/stdc++.h>
using namespace std;
// Using Recursion
class Solution {
    public:
        // Using Recursion
        bool isTargetSumSubset_Rec(vector<int> &arr,int target,int n) { // Tc : O(2^n)
            // Base Case
            if(n == 0) {
                return false;
            }
            if(target == 0 or (target == 0 and n == 0)) {
                return true;
            }

            if(arr[n-1] <= target) {
                // include curr
                bool ans1 = isTargetSumSubset_Rec(arr,target-arr[n-1],n-1);
                // exclude curr
                bool ans2 = isTargetSumSubset_Rec(arr,target,n-1);
                return ans1 or ans2;
            } else {
                return isTargetSumSubset_Rec(arr,target,n-1);
            }
        }

        // Using Memoization
        bool isTargetSumSubset_Mem(vector<int> &arr,int target,int n,vector<vector<bool>> &dp) { // TC : O(n*target)
            // Base Case
            if(n == 0) {
                return false;
            }
            if(target == 0 or (target == 0 and n == 0)) {
                return true;
            }

            if(dp[n-1][target]) {
                return dp[n-1][target];
            }

            if(arr[n-1] <= target) {
                // include curr
                bool ans1 = isTargetSumSubset_Mem(arr,target-arr[n-1],n-1,dp);
                // exclude curr
                bool ans2 = isTargetSumSubset_Mem(arr,target,n-1,dp);
                return dp[n][target] = ans1 or ans2;
            } else {
                return dp[n][target] = isTargetSumSubset_Mem(arr,target,n-1,dp);
            }
        }

        // Using Tabulation
        bool isTargetSumSubset_Tab(vector<int> &arr,int n,int target) { // TC: O(N*Target), SC : O(N*Target)
            vector<vector<bool>> dp(n+1, vector<bool>(target+1,0));
            // dp[i][j] denotes if by considering i items is it possible to  make sum = j  

            // 1. if items are zero in array then the target sum is not possible, return false;
            // All are by default zero

            // 2. if targetSum is zero, not matter how many are the items in arrays the we return true 
            for(int i = 1; i <= n; i++) {
                dp[i][0] = 1;
            }
            // 3. if items and targetSum is zero then it is achievable then return true
            dp[0][0] = 1;

            // Fill table in bottom up manner
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= target; j++) {
                    int curr = arr[i-1];
                    if(curr <= j and dp[i-1][j-curr]) {
                        dp[i][j] = 1;
                    } else if(dp[i-1][j]) {
                        dp[i][j] = 1;
                    }
                }
            }
            return dp[n][target];
        }
        // Using Tabulation space optimized
        bool isTargetSumSubset_Tab_OP(vector<int> &arr,int n,int target) { // TC : O(N*Target), SC : O(Target)
            vector<bool> curr(target+1,0), prev(target+1,0);
            // Base case
            curr[0] = prev[0] = 1;

            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= target; j++){
                    int cr = arr[i-1];
                    if(cr <= j and prev[j-cr]) {
                        curr[j] = 1;
                    } else if(prev[j]) {
                        curr[j] = 1;
                    }
                }
                prev = curr;
            }
            return curr[target];
        }    
};


int main()
{
    vector<int> arr = {1,2,3,4};
    int target = 4;
    Solution obj;

    cout << obj.isTargetSumSubset_Rec(arr,target,arr.size()) << endl;
    vector<vector<bool>> dp(arr.size()+1, vector<bool>(target+1,0));
    cout << obj.isTargetSumSubset_Mem(arr,target,arr.size(),dp) << endl;
    cout << obj.isTargetSumSubset_Tab(arr,arr.size(),target) << endl;
    cout << obj.isTargetSumSubset_Tab_OP(arr,arr.size(),target);


    return 0;
}
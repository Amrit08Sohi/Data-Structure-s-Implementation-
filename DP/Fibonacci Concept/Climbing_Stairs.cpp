#include<bits/stdc++.h>
using namespace std;
// Climbing Stairs problem : Variation of Fibonacci
/*
Problem : There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.
*/

// Brute Force Approach : Using Recursion
// Time Complexity : O(2^n)
// Space Complexity : O(n)
long nthStair(int n) {
    /* This code block is checking if the input `n` is either 0 or 1. If it is, then it returns `n`
    itself. This is because if there are 0 or 1 stairs, there is only one way to climb them, i.e.,
    by not climbing at all or climbing just one step. */
    if(n == 0 or n == 1) {
        return 1;
    } 
    return nthStair(n-1) + nthStair(n-2);
}


// optimized Approach : Using Memoization
// Time Complexity : O(n)
// Space Complexity : O(n)

/**
 * The function calculates the number of ways to climb n stairs using either 1 or 2 steps at a time,
 * using dynamic programming to store previously calculated values.
 * 
 * @param n The parameter "n" represents the number of stairs in a staircase.
 * @param dp dp is a reference to a vector of long integers. It is being used to store the results of
 * previously computed subproblems in order to avoid redundant computations and improve the efficiency
 * of the algorithm. The value of dp[n] represents the number of distinct ways to climb n stairs using
 * 1 or 2
 * 
 * @return The function `nthStair_Util` is returning a `long` value, which is the number of ways to
 * climb `n` stairs using 1 or 2 steps at a time.
 */
long nthStair_Util(int n, vector<long> &dp) {
    if(n == 0 or n == 1) {
        return 1;
    } 

    if(dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = nthStair_Util(n-1,dp) + nthStair_Util(n-2,dp); 
}

long nthStair_memoized(int n) {
    vector<long> dp(n+1,-1);
    return nthStair_Util(n,dp);
}

// optimized Approach : Using Tabulation
// Time Complexity : O(n)
// Space Complexity : O(n)

/**
 * The function uses tabulation to calculate the number of ways to climb n stairs, where a person can
 * climb 1 or 2 stairs at a time.
 * 
 * @param n The input parameter "n" represents the number of stairs in a staircase. The function
 * "nthStair_tabulated" uses dynamic programming with tabulation to calculate the number of ways to
 * climb the staircase with n stairs, where a person can climb either 1 or 2 stairs at a time.
 * 
 * @return The function `nthStair_tabulated` returns the number of distinct ways to climb `n` stairs
 * using 1 or 2 steps at a time, using a tabulated dynamic programming approach.
 */
long nthStair_tabulated(int n) {
    vector<long> dp(n+1);
    // Initialize with base case
    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// optimized Approach : Using DP Space optimized
// Time Complexity : O(n)
// Space Complexity : O(1)

/**
 * The function calculates the number of ways to climb n stairs using dynamic programming with
 * optimized space complexity.
 * 
 * @param n The parameter "n" represents the number of stairs in a staircase. The function
 * "nthStair_optimized" returns the number of ways to climb the staircase if a person can take either 1
 * or 2 steps at a time.
 * 
 * @return The function `nthStair_optimized` returns the number of ways to climb `n` stairs using 1 or
 * 2 steps at a time, using an optimized iterative approach.
 */
long nthStair_optimized(int n) {
    if(n == 0) return 1;
    int a = 0, b = 1;
    int c;

    while(n--) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;

    // Brute Force Solution o/p
    cout << nthStair(n); 
    cout << endl;

    //  Memoized Solution
    cout << nthStair_memoized(n); 
    cout << endl;

    //  Tabulated Solution
    cout << nthStair_tabulated(n); 
    cout << endl;

    //  Tabulated space optimized Solution
    cout  << nthStair_optimized(n);

    return 0;
}
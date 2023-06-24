#include<bits/stdc++.h>
using namespace std;
// Fibonacci Series : 0 1 1 2 3 5 8 13 21
// Recurrence Relation : fib(n) = fib(n-1) + fib(n-2)

// Generating fibonacci Series using recursion upto nth index
// Time Complexity : O(n*2^n)
// Space Complexity : O(n)
/**
 * The function recursively calculates the nth Fibonacci number.
 * 
 * @param n The parameter "n" represents the index of the Fibonacci number to be calculated using
 * recursion. For example, if n=5, the function will return the 5th Fibonacci number.
 * 
 * @return The function `fib_Rec_Util` is a recursive function that calculates the nth Fibonacci
 * number. It returns the nth Fibonacci number as an integer value.
 */

int fib_Rec_Util(int n) { 
    // Base Case
    if(n == 0 or n == 1) {
        return n;
    }
    return fib_Rec_Util(n-1) + fib_Rec_Util(n-2);
}

void fib_Rec(int n) {
    for (int i = 0; i < n; i++)
    {
        cout << fib_Rec_Util(i) << " ";
    }
    cout << endl;
}

// Generating fibonacci Series using advanced or optimized recursion(memoization) upto nth index
// Time Complexity : O(n)
// Space Complexity : O(n) + O(n)(Recursion Stack space)

/**
 * This is a recursive function that calculates the nth Fibonacci number using memoization technique.
 * 
 * @param n The input integer for which we want to calculate the nth Fibonacci number.
 * @param dp dp is a vector that is being used to store the previously calculated Fibonacci numbers. It
 * is being passed as a reference to the function fib_memoized_util so that the function can access and
 * modify its values. The vector is initialized with -1 values, and if the function finds that the
 * value for
 * 
 * @return The function `fib_memoized_util` is returning the nth Fibonacci number using memoization
 * technique.
 */
int fib_memoized_util(int n,vector<int> &dp) {
    if(n == 0 or n == 1) {
        return n;
    }
    if(dp[n-1] != -1) {
        return dp[n-1];
    }
    return dp[n-1] = fib_memoized_util(n-1,dp) + fib_memoized_util(n-2,dp);
}

void fib_memoized(int n) {
    vector<int> dp(n,-1);

    for(int i = 0; i < n; i++) {
        cout << fib_memoized_util(i,dp) << " ";
    }
    cout << endl;
}

// Generating fibonacci Series using advanced or optimized recursion(tabulation) upto nth index
// Time Complexity : O(n)
// Space Complexity : O(n)
/**
 * The function calculates and prints the Fibonacci sequence up to a given number using tabulation.
 * 
 * @param n The parameter "n" represents the number of terms in the Fibonacci sequence that we want to
 * generate using the tabulated (bottom-up) approach.
 */
void fib_tabulated(int n) {
    vector<int> dp(n);
    // Initialize with base case
    dp[0] = 0;
    dp[1] = 1;
    cout << dp[0] << " " << dp[1] << " ";
    // Fill dp in Bottom up manner
    for(int i = 2; i < n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        cout << dp[i] << " ";
    }
    cout << endl;
}


// Generating fibonacci Series Using Iteration upto nth index
// Time Complexity : O(n)
// Space Complexity : O(1)

/**
 * This function prints the first n numbers of the Fibonacci sequence.
 * 
 * @param n The parameter "n" in the function "fib" represents the number of terms of the Fibonacci
 * sequence that the function should generate and print.
 */
void fib(int n) {
    int a = 0, b = 1;
    int c;

    while(n--) {
        cout << a << " ";
        c = a+b;
        a = b;
        b = c;
    }
}



int main()
{
    int n;
    cin >> n;

    // Fibonacci Using Recursion
    fib_Rec(n);

    // Fibonacci Using Memoization
    fib_memoized(n);

    // Fibonacci Using Tabulation
    fib_tabulated(n);

    // Fibonacci Using Iteration
    fib(n);





    
    return 0;
}
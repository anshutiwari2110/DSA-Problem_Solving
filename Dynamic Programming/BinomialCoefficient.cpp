/**
 * @file BinomialCoefficient.cpp
 * C(n, k) = C(n-1, k-1) + C(n-1, k)
 * C(n, 0) = C(n, n) = 1
 */

#include<bits/stdc++.h>

using namespace std;
int MOD = 1e9 + 7;
    
int nCr(int n, int k, vector<vector<int>> &dp){
    if(dp[n][k] != -1) return dp[n][k];
    if(k == 0 || k == n){
        dp[n][k] = 1;
        return dp[n][k];
    }
        
    dp[n][k] = nCr(n-1,k-1,dp) % MOD + nCr(n-1,k,dp) % MOD;
    return dp[n][k] % MOD;
        
}
int nCr(int n, int r){
    // code here
    if(r > n) return 0;
        
    vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
        
    return nCr(n,r,dp) % MOD;
}

int main(){
    int n = 5, k = 2;
    cout << "Value of C(" << n << ", " << k << ") is " 
         << nCr(n, k) << endl;
    return 0;
}
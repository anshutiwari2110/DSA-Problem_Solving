#include<bits/stdc++.h>

using namespace std;

int matrix(int arr[],int i, int j, vector<vector<int>> &dp){
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
        
    dp[i][j] = INT_MAX;
        
    for(int k = i;k<j;k++){
        dp[i][j] = min(dp[i][j],matrix(arr,i,k,dp) + matrix(arr,k+1,j,dp) + arr[i-1]*arr[j]*arr[k]);
    }
    return dp[i][j];
}
int matrixMultiplication(int N, int arr[]){
    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    return matrix(arr,1,N-1,dp);
}

int main(){
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Minimum number of multiplications is : "
         << matrixMultiplication(n, arr);
}
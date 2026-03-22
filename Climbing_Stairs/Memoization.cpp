#include<iostream>
#include<vector>
using namespace std;

int ways(int n , vector<int>& dp){
    if(n <= 1)return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = ways(n-1 , dp) + ways(n-2 , dp);
}

int main() {
    int n;
    cin >> n;
    vector<int>dp(n+1, -1);
    cout << ways(n, dp);
    return 0;
}
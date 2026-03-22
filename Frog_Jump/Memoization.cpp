#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int jumps(int idx , vector<int>& dp , vector<int>& heights){
    if(idx == 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    int left = jumps(idx-1 , dp , heights) + abs(heights[idx] - heights[idx-1]);

    int right = 1e9;
    if(idx > 1){
        right = jumps(idx-2 , dp , heights) + abs(heights[idx] - heights[idx-2]);
    }

    return dp[idx] = min(left , right);
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    vector<int> dp(n , -1);

    cout <<"Minimum Cost of Jumps is : " << jumps(n-1 , dp , heights);

    return 0;
}
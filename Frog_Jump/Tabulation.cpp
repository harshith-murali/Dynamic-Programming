#include<iostream>
#include<vector>
using namespace std;

int main() {
     int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    vector<int> dp(n , -1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int fs = abs(heights[i] - heights[i-1]) + dp[i-1];
        int ss = 1e9;
        if(i > 1){
            ss = abs(heights[i] - heights[i-2]) + dp[i-2];
        }
        dp[i] = min(ss , fs);
    }

    for(int x : dp){
        cout << x <<" ";
    }
    cout <<endl;

    return 0;
}
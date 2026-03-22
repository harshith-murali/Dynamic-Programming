#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    int k;
    cin >> k;

    vector<int> dp(n , 0);
    dp[0] = 0;

    for(int idx = 1; idx < n; idx++){
        int minCost = 1e9;

        for(int j = 1; j <= k; j++){
            if(idx - j >= 0){
                int cost = dp[idx-j] + abs(heights[idx] - heights[idx-j]);
                minCost = min(minCost , cost);
            }
        }

        dp[idx] = minCost;
    }

    cout << dp[n-1] << endl;

    return 0;
}
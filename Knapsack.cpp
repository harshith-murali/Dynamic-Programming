#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    int f(int idx, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {

        if (idx == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        if (dp[idx][W] != -1) return dp[idx][W];

        int notTake = f(idx - 1, W, val, wt, dp);

        int take = INT_MIN;
        if (wt[idx] <= W)
            take = val[idx] + f(idx - 1, W - wt[idx], val, wt, dp);

        return dp[idx][W] = max(take, notTake);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {

        int n = val.size();

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return f(n - 1, W, val, wt, dp);
    }
};

int main() {

    Solution obj;

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    cout << obj.knapsack(W, val, wt);

}
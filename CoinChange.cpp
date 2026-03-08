#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int f(int idx, int sum, vector<int>& coins, vector<vector<int>>& dp) {

        if (idx == 0) {
            if (sum % coins[0] == 0) return sum / coins[0];
            return 1e9;
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        int notTake = f(idx - 1, sum, coins, dp);

        int take = 1e9;
        if (coins[idx] <= sum)
            take = 1 + f(idx, sum - coins[idx], coins, dp);

        return dp[idx][sum] = min(take, notTake);
    }

    int minCoins(vector<int>& coins, int sum) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        int ans = f(n - 1, sum, coins, dp);

        if (ans >= 1e9) return -1;

        return ans;
    }
};
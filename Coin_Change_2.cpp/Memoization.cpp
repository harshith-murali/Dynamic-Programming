#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(int i, int tar, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            return (tar % coins[0] == 0);
        }

        if (dp[i][tar] != -1) return dp[i][tar];

        int notPick = f(i - 1, tar, coins, dp);
        int pick = 0;

        if (tar >= coins[i]) {
            pick = f(i, tar - coins[i], coins, dp);
        }

        return dp[i][tar] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return f(n - 1, amount, coins, dp);
    }
};
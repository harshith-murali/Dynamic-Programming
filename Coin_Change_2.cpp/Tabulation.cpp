#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int t = 0; t <= amount; t++) {
            dp[0][t] = (t % coins[0] == 0);
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int notPick = dp[i - 1][t];
                int pick = 0;

                if (t >= coins[i]) {
                    pick = dp[i][t - coins[i]];
                }

                dp[i][t] = pick + notPick;
            }
        }

        return dp[n - 1][amount];
    }
};
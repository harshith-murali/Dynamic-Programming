#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++) {
            for (int t = coins[i]; t <= amount; t++) {
                dp[t] += dp[t - coins[i]];
            }
        }

        return dp[amount];
    }
};
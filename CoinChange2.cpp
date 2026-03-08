#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(int idx, int sum, vector<int>& coins, vector<vector<int>>& dp) {

        if (idx == 0) {
            return (sum % coins[0] == 0);
        }

        if (dp[idx][sum] != -1) return dp[idx][sum];

        int notTake = f(idx - 1, sum, coins, dp);

        int take = 0;
        if (coins[idx] <= sum)
            take = f(idx, sum - coins[idx], coins, dp);

        return dp[idx][sum] = (take + notTake) % MOD;
    }

    int count(vector<int>& coins, int sum) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return f(n - 1, sum, coins, dp);
    }
};

int main() {

    Solution obj;

    vector<int> coins = {1, 2, 5};
    int sum = 5;

    cout << obj.count(coins, sum);

}
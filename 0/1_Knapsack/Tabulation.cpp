#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case
        for (int cap = wt[0]; cap <= W; cap++) {
            dp[0][cap] = val[0];
        }

        // Fill DP table
        for (int idx = 1; idx < n; idx++) {
            for (int cap = 0; cap <= W; cap++) {

                int notPick = dp[idx - 1][cap];

                int pick = 0;
                if (cap >= wt[idx]) {
                    pick = val[idx] + dp[idx - 1][cap - wt[idx]];
                }

                dp[idx][cap] = max(pick, notPick);
            }
        }

        return dp[n - 1][W];
    }
};

int main() {
    Solution obj;

    int n = 3;
    vector<int> val = {6, 10, 12};
    vector<int> wt = {1, 2, 3};
    int W = 5;

    cout << "Maximum value: " << obj.knapsack(W, val, wt) << endl;

    return 0;
}
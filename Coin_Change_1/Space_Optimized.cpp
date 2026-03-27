#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0);

        // base case
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) prev[t] = t / coins[0];
            else prev[t] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(amount + 1, 0); // NEW ARRAY EVERY TIME

            for (int t = 0; t <= amount; t++) {

                int notPick = prev[t];

                int pick = 1e9;
                if (t >= coins[i]) {
                    pick = 1 + curr[t - coins[i]]; // SAME ROW (curr)
                }

                curr[t] = min(pick, notPick);
            }

            prev = curr;
        }

        int ans = prev[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};
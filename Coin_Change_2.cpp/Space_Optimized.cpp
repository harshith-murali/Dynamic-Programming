#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0);

        // base case
        for (int t = 0; t <= amount; t++) {
            prev[t] = (t % coins[0] == 0);
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(amount + 1, 0); // NEW ARRAY

            for (int t = 0; t <= amount; t++) {

                int notPick = prev[t];

                int pick = 0;
                if (t >= coins[i]) {
                    pick = curr[t - coins[i]]; // SAME ROW
                }

                curr[t] = pick + notPick;
            }

            prev = curr;
        }

        return prev[amount];
    }
};
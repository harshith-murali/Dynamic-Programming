#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base case
        for (int j = 0; j <= capacity; j++) {
            dp[0][j] = (j / wt[0]) * val[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int cap = 0; cap <= capacity; cap++) {
                int notPick = dp[idx - 1][cap];

                int pick = INT_MIN;
                if (cap >= wt[idx]) {
                    pick = val[idx] + dp[idx][cap - wt[idx]];
                }

                dp[idx][cap] = max(pick, notPick);
            }
        }

        return dp[n - 1][capacity];
    }
};

int main() {
    Solution obj;
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;

    cout << obj.knapSack(val, wt, capacity);
    return 0;
}
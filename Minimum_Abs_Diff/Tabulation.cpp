#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int k = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // base case
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        // DP fill
        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= k; target++) {

                bool notPick = dp[idx - 1][target];

                bool pick = false;
                if (target >= arr[idx]) {
                    pick = dp[idx - 1][target - arr[idx]];
                }

                dp[idx][target] = pick || notPick;
            }
        }

        // find minimum difference
        int mini = 1e9;

        for (int s1 = 0; s1 <= k; s1++) {
            if (dp[n - 1][s1]) {
                mini = min(mini, abs(sum - 2 * s1));
            }
        }

        return mini;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {2, 7, 4, 1, 8, 1};

    cout << obj.lastStoneWeightII(arr);
}
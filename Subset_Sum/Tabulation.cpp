
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (sum % 2 != 0) return false;

        int k = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // base case
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (arr[0] <= k)
            dp[0][arr[0]] = true;

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

        return dp[n - 1][k];
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 5, 11, 5};

    cout << (obj.canPartition(nums) ? "True" : "False");
}
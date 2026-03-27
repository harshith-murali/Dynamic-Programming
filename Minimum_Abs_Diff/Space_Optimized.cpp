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

        vector<bool> dp(k + 1, false);

        dp[0] = true;

        // build DP
        for (int i = 0; i < n; i++) {
            for (int target = k; target >= arr[i]; target--) {
                dp[target] = dp[target] || dp[target - arr[i]];
            }
        }

        // find minimum difference
        int mini = 1e9;

        for (int s1 = 0; s1 <= k; s1++) {
            if (dp[s1]) {
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
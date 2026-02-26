#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int helper(int idx, vector<int>& height, vector<int>& dp) {
        if (idx == 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int left = helper(idx - 1, height, dp)
                   + abs(height[idx] - height[idx - 1]);

        int right = INT_MAX;
        if (idx > 1) {
            right = helper(idx - 2, height, dp)
                    + abs(height[idx] - height[idx - 2]);
        }

        return dp[idx] = min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return helper(n - 1, height, dp);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution sol;
    cout << sol.minCost(height) << endl;

    return 0;
}
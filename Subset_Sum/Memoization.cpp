#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool f(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (idx == 0) return (nums[0] == target);

        if (dp[idx][target] != -1) return dp[idx][target];

        bool notPick = f(idx - 1, target, nums, dp);

        bool pick = false;
        if (target >= nums[idx])
            pick = f(idx - 1, target - nums[idx], nums, dp);

        return dp[idx][target] = pick || notPick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, dp);
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 5, 11, 5};

    cout << (obj.canPartition(nums) ? "True" : "False");
}
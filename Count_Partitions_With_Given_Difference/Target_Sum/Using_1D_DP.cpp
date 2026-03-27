#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum + target < 0 || (totalSum + target) % 2 != 0)
            return 0;

        int req = (totalSum + target) / 2;

        vector<int> dp(req + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = req; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[req];
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << obj.findTargetSumWays(nums, target) << endl;

    return 0;
}
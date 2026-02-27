#include <iostream>
#include <vector>
using namespace std;

int frogWithKJump(int n, int k, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int cost = dp[i - j] + abs(heights[i] - heights[i - j]);
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
}

/**
 * SPACE OPTIMIZATION
 * class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int take = nums[i] + prev2;
            int notTake = prev;
            int curri = max(take, notTake);

            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
 */
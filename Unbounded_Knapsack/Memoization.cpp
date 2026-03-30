#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int helper(int idx, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (idx == 0) {
            return (capacity / wt[0]) * val[0];
        }

        if (dp[idx][capacity] != -1) return dp[idx][capacity];

        int notPick = helper(idx - 1, capacity, val, wt, dp);

        int pick = INT_MIN;
        if (capacity >= wt[idx]) {
            pick = val[idx] + helper(idx, capacity - wt[idx], val, wt, dp);
        }

        return dp[idx][capacity] = max(pick, notPick);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

        return helper(n - 1, capacity, val, wt, dp);
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
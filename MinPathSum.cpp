#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return INT_MAX;
        if (i == 0 && j == 0) return grid[0][0];

        if (dp[i][j] != -1) return dp[i][j];

        int up = f(i - 1, j, grid, dp);
        int left = f(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, grid, dp);
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << s.minPathSum(grid) << endl;
    return 0;
}
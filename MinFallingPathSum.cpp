#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (j < 0 || j >= m) return INT_MAX;

        if (i == 0) return grid[0][j];

        if (dp[i][j] != -1) return dp[i][j];

        int up = f(i - 1, j, grid, dp);
        int leftDiag = f(i - 1, j - 1, grid, dp);
        int rightDiag = f(i - 1, j + 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, min(leftDiag, rightDiag));
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, f(n - 1, j, grid, dp));
        }

        return ans;
    }
};

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter grid values:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << "Minimum Falling Path Sum: " << obj.minFallingPathSum(grid) << endl;

    return 0;
}
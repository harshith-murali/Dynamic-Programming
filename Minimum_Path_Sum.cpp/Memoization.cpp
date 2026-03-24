#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return 1e9;

    if (dp[i][j] != -1) return dp[i][j];

    int left = grid[i][j] + helper(i, j - 1, grid, dp);
    int up = grid[i][j] + helper(i - 1, j, grid, dp);

    return dp[i][j] = min(left, up);
}

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return helper(n - 1, m - 1, grid, dp);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << minPathSum(grid) << endl;

    return 0;
}
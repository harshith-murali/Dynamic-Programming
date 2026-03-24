#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if (i < 0 || j < 0) return 0;
    if (grid[i][j] == 1) return 0;
    if (i == 0 && j == 0) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = helper(i, j - 1, grid, dp) + helper(i - 1, j, grid, dp);
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1) return 0;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n - 1, m - 1, obstacleGrid, dp);
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

    cout << uniquePathsWithObstacles(grid) << endl;

    return 0;
}
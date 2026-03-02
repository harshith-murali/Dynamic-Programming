#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m, 0);

        if (grid[0][0] == 1) return 0;
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[m - 1];
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    cout << s.uniquePathsWithObstacles(grid) << endl;
    return 0;
}
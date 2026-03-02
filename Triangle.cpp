#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (j < 0 || j > i) return INT_MAX;

        if (i == 0) return triangle[0][0];

        if (dp[i][j] != -1) return dp[i][j];

        int up = f(i - 1, j, triangle, dp);
        int leftDiagonal = f(i - 1, j - 1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(up, leftDiagonal);
    }

    int minPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, f(n - 1, j, triangle, dp));
        }

        return ans;
    }
};

int main() {
    Solution s;

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << s.minPathSum(triangle) << endl;
    return 0;
}
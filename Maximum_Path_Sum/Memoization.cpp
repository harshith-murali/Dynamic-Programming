#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();

        if(j < 0 || j >= n) return 1e9;

        if(i == 0) return matrix[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + helper(i-1, j, matrix, dp);
        int leftDiag = matrix[i][j] + helper(i-1, j-1, matrix, dp);
        int rightDiag = matrix[i][j] + helper(i-1, j+1, matrix, dp);

        return dp[i][j] = min(up, min(leftDiag, rightDiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = 1e9;

        for(int j = 0; j < n; j++){
            ans = min(ans, helper(n-1, j, matrix, dp));
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };

    cout << sol.minFallingPathSum(matrix);
    return 0;
}
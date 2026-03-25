#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n , vector<int>(n, 0));

        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){

                int up = matrix[i][j] + dp[i-1][j];

                int leftDiag = (j > 0) ? matrix[i][j] + dp[i-1][j-1] : 1e9;

                int rightDiag = (j < n-1) ? matrix[i][j] + dp[i-1][j+1] : 1e9;

                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }

        int ans = 1e9;
        for(int j = 0; j < n; j++){
            ans = min(ans, dp[n-1][j]);
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
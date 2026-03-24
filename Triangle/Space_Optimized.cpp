#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        
        // Initialize with last row
        for(int j = 0; j < n; j++){
            dp[j] = triangle[n-1][j];
        }

        // Bottom-up
        for(int i = n-2; i >= 0; i--){
            vector<int> curr(i+1);
            
            for(int j = 0; j <= i; j++){
                int down = triangle[i][j] + dp[j];
                int diag = triangle[i][j] + dp[j+1];
                curr[j] = min(down, diag);
            }

            dp = curr;
        }

        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << sol.minimumTotal(triangle);
    return 0;
}
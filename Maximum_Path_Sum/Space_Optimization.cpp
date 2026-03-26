#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);

        // Base row
        for(int j = 0; j < n; j++){
            prev[j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            vector<int> curr(n);  

            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + prev[j];
                int leftDiag = (j > 0) ? matrix[i][j] + prev[j-1] : 1e9;
                int rightDiag = (j < n-1) ? matrix[i][j] + prev[j+1] : 1e9;

                curr[j] = min({up, leftDiag, rightDiag});
            }

            prev = curr;
        }

        int ans = 1e9;
        for(int j = 0; j < n; j++){
            ans = min(ans, prev[j]);
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
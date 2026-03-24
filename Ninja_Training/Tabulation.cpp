  #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));

        for (int day = 1; day < n; day++) {
            for (int lastTask = 0; lastTask < 4; lastTask++) {

                dp[day][lastTask] = 0;

                for (int task = 0; task < 3; task++) {
                    if (task != lastTask) {
                        int points = mat[day][task] + dp[day - 1][task];
                        dp[day][lastTask] = max(dp[day][lastTask], points);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    Solution obj;
    cout << obj.maximumPoints(mat) << endl;

    return 0;
}

// Time Complexity: O(n*4*3) => O(n)
// Space Complexity: O(n*4) => O(n)
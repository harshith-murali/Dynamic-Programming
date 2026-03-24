#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int helper(int day, int lastTask, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != lastTask) {
                    maxi = max(maxi, mat[0][task]);
                }
            }
            return maxi;
        }

        if (dp[day][lastTask] != -1) return dp[day][lastTask];

        int maxiPoints = INT_MIN;

        for (int task = 0; task < 3; task++) {
            if (task != lastTask) {
                int points = mat[day][task] + helper(day - 1, task, mat, dp);
                maxiPoints = max(maxiPoints, points);
            }
        }

        return dp[day][lastTask] = maxiPoints;
    }

    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n - 1, 3, mat, dp);
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(3));

    cout << "Enter points for 3 tasks each day:\n";
    for (int i = 0; i < n; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    Solution obj;
    int result = obj.maximumPoints(mat);

    cout << "Maximum Points: " << result << endl;

    return 0;
}

// Time Complexity: O(n*4*3) => O(n)
// Space Complexity: O(n*4) => O(n)
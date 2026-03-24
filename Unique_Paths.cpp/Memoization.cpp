#include <iostream>
#include <vector>
using namespace std;

int helper(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int left = helper(i, j - 1, dp);
    int up = helper(i - 1, j, dp);

    return dp[i][j] = left + up;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m - 1, n - 1, dp);
}

int main() {
    int m, n;
    
    cout << "Enter rows (m): ";
    cin >> m;
    
    cout << "Enter columns (n): ";
    cin >> n;

    int result = uniquePaths(m, n);

    cout << "Number of unique paths: " << result << endl;

    return 0;
}
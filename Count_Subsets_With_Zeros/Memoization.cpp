#include <iostream>
#include <vector>
using namespace std;

int MOD = 1e9 + 7;

int solve(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case
    if (idx == 0) {
        if (sum == 0 && arr[0] == 0) return 2;
        if (sum == 0 || sum == arr[0]) return 1;
        return 0;
    }

    if (dp[idx][sum] != -1) return dp[idx][sum];

    int notTake = solve(idx - 1, sum, arr, dp);

    int take = 0;
    if (arr[idx] <= sum) {
        take = solve(idx - 1, sum - arr[idx], arr, dp);
    }

    return dp[idx][sum] = (take + notTake) % MOD;
}

int countSubsets(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

int main() {
    vector<int> arr = {0, 0, 1};
    int k = 1;

    cout << countSubsets(arr, k) << endl;
    return 0;
}
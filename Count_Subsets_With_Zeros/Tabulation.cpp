#include <iostream>
#include <vector>
using namespace std;

int MOD = 1e9 + 7;

int countSubsets(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // 🔹 Base Case (idx = 0)
    if (arr[0] == 0)
        dp[0][0] = 2;   // take & not take
    else
        dp[0][0] = 1;   // not take

    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;

    // 🔹 Fill DP Table
    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= k; sum++) {

            int notTake = dp[i - 1][sum];

            int take = 0;
            if (arr[i] <= sum)
                take = dp[i - 1][sum - arr[i]];

            dp[i][sum] = (take + notTake) % MOD;
        }
    }

    return dp[n - 1][k];
}

int main() {
    vector<int> arr = {0, 0, 1};
    int k = 1;

    cout << countSubsets(arr, k) << endl;  // Output: 4
    return 0;
}
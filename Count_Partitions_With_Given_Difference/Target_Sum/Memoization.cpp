#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int notPick = f(idx - 1, target, arr, dp);

        int pick = 0;
        if (target >= arr[idx]) {
            pick = f(idx - 1, target - arr[idx], arr, dp);
        }

        return dp[idx][target] = (pick + notPick) % MOD;
    }

    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (sum - diff < 0) return 0;
        if ((sum - diff) % 2 != 0) return 0;

        int target = (sum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, arr, dp);
    }
};

int main() {
    Solution obj;

    vector<int> arr = {0, 0, 1, 2, 3};
    int diff = 1;

    cout << obj.countPartitions(arr, diff) << endl;

    return 0;
}
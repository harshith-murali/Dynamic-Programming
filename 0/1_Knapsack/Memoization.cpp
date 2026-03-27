#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int f(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
        if (idx == 0) {
            if (W >= wt[0]) return val[0];
            else return 0;
        }

        if (dp[idx][W] != -1) return dp[idx][W];

        int notPick = f(idx - 1, W, val, wt, dp);
        int pick = INT_MIN;

        if (W >= wt[idx]) {
            pick = val[idx] + f(idx - 1, W - wt[idx], val, wt, dp);
        }

        return dp[idx][W] = max(pick, notPick);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, val, wt, dp);
    }
};

int main() {
    Solution obj;

    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];

    cout << "Enter capacity: ";
    cin >> W;

    int ans = obj.knapsack(W, val, wt);
    cout << "Maximum value: " << ans << endl;

    return 0;
}
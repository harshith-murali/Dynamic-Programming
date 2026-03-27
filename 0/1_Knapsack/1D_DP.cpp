#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int cap = W; cap >= wt[i]; cap--) {
                dp[cap] = max(dp[cap], val[i] + dp[cap - wt[i]]);
            }
        }

        return dp[W];
    }
};

int main() {
    Solution obj;

    vector<int> val = {6, 10, 12};
    vector<int> wt = {1, 2, 3};
    int W = 5;

    cout << "Maximum value: " << obj.knapsack(W, val, wt) << endl;

    return 0;
}
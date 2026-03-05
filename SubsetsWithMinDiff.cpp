#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base cases
        for(int i = 0; i < n; i++) dp[i][0] = true;

        if(arr[0] <= sum)
            dp[0][arr[0]] = true;

        // Fill DP table
        for(int i = 1; i < n; i++){
            for(int target = 1; target <= sum; target++){

                bool notTake = dp[i-1][target];

                bool take = false;
                if(arr[i] <= target)
                    take = dp[i-1][target - arr[i]];

                dp[i][target] = take || notTake;
            }
        }

        int mini = INT_MAX;

        for(int s1 = 0; s1 <= sum/2; s1++){
            if(dp[n-1][s1]){
                int diff = abs(sum - 2*s1);
                mini = min(mini, diff);
            }
        }

        return mini;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {1, 6, 11, 5};

    cout << obj.minDifference(arr) << endl;

    return 0;
}
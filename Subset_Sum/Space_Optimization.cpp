#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (sum % 2 != 0) return false;

        int k = sum / 2;

        vector<bool> prev(k + 1, false);

        // base case
        prev[0] = true;

        if (arr[0] <= k)
            prev[arr[0]] = true;

        for (int idx = 1; idx < n; idx++) {

            vector<bool> curr(k + 1, false);
            curr[0] = true;  // 🔥 important

            for (int target = 1; target <= k; target++) {

                bool notPick = prev[target];

                bool pick = false;
                if (target >= arr[idx]) {
                    pick = prev[target - arr[idx]];
                }

                curr[target] = pick || notPick;
            }

            prev = curr;
        }

        return prev[k];
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 5, 11, 5};

    cout << (obj.canPartition(nums) ? "True" : "False");
}
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (idx == 0)
            return arr[0] == target;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = f(idx - 1, target, arr, dp);
        bool take = false;

        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr, dp);

        return dp[idx][target] = take || notTake;
    }

    bool equalPartition(vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, arr, dp);
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {1, 5, 11, 5};

    if (obj.equalPartition(arr))
        cout << "Can be partitioned\n";
    else
        cout << "Cannot be partitioned\n";

    return 0;
}
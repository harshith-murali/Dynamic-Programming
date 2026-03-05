#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (idx == 0)
            return (arr[0] == target);

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = f(idx - 1, target, arr, dp);
        bool take = false;

        if (arr[idx] <= target)
            take = f(idx - 1, target - arr[idx], arr, dp);

        return dp[idx][target] = (take || notTake);
    }

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (obj.isSubsetSum(arr, sum))
        cout << "Subset exists\n";
    else
        cout << "Subset does not exist\n";

    return 0;
}
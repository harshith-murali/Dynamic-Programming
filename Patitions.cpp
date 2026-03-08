#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int f(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (idx == 0)
        {
            if (sum == 0 && arr[0] == 0)
                return 2;
            if (sum == 0 || sum == arr[0])
                return 1;
            return 0;
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int notTake = f(idx - 1, sum, arr, dp);

        int take = 0;
        if (arr[idx] <= sum)
            take = f(idx - 1, sum - arr[idx], arr, dp);

        return dp[idx][sum] = take + notTake;
    }

    int countPartitions(vector<int> &arr, int diff)
    {

        int n = arr.size();

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum - diff < 0 || (totalSum - diff) % 2)
            return 0;

        int target = (totalSum - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, arr, dp);
    }
};

int main()
{

    Solution obj;

    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;

    cout << obj.countPartitions(arr, diff);
}
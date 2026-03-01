#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int f(int a, int b, vector<vector<int>> &dp)
    {
        if (a == 0 && b == 0)
            return 1;
        if (a < 0 || b < 0)
            return 0;

        if (dp[a][b] != -1)
            return dp[a][b];

        int up = f(a - 1, b, dp);
        int left = f(a, b - 1, dp);

        return dp[a][b] = up + left;
    }

    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a, vector<int>(b, -1));
        return f(a - 1, b - 1, dp);
    }
};

int main()
{
    int a, b;
    cin >> a >> b;

    Solution obj;
    cout << obj.NumberOfPath(a, b) << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) dp[0][0] = grid[0][0];
            else{
                int left = grid[i][j] + (j > 0 ? dp[i][j-1] : 1e9);
                int up = grid[i][j] + (i > 0 ? dp[i-1][j] : 1e9);
                dp[i][j] = min(left, up);
            }
        }
    }

    cout << dp[n-1][m-1] << endl;
    return 0;
}
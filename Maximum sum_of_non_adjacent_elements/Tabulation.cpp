#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n , -1);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for(int i=1; i<n; i++){
        
        int pick = arr[i];
        if(i > 1) pick += dp[i-2];
        int notPick = dp[i-1];

        dp[i] = max(pick , notPick);
    }
    cout << dp[n-1];
    
    return 0;
}
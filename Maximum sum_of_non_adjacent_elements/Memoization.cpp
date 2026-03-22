#include<iostream>
#include<vector>
using namespace std;

int sum(int idx , vector<int> & arr , vector<int>& dp){
    if(idx == 0){
        return arr[idx];
    }
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int pick = arr[idx] + sum(idx-2 , arr , dp);
    int notPick = sum(idx-1 , arr , dp);
    return dp[idx] = max(pick , notPick);
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n , -1);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<sum(n-1 , arr , dp);
    return 0;
}
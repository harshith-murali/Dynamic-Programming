// overlapping subproblems
// optimal substructure

// memoization : store the results of the subproblems in a hash map or an array and return the stored result when the same subproblem is encountered again
#include <iostream>
#include<vector>
using namespace std;
int fib(int n, vector<int>& dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    vector<int> dpTab(n+1);
    dpTab[0] = 0;
    dpTab[1] = 1;
    for(int i=2; i<=n; i++){
        dpTab[i] = dpTab[i-1] + dpTab[i-2];
    }

    for(int i=0; i<=n; i++){
        cout<<dpTab[i]<<" ";
    }
    cout<<endl;

    int prev2 = 0, prev1 = 1, curr;
    for(int i=2; i<=n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<curr<<endl;
    cout<<fib(n, dp);
}
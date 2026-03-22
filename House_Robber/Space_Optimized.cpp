#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int>& arr, int start, int end){
    int prev2 = 0;
    int prev = arr[start];

    for(int i = start + 1; i <= end; i++){
        int pick = arr[i];
        if(i > start + 1) pick += prev2;

        int notPick = prev;

        int curr = max(pick , notPick);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main() {
    int n;
    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(n == 1){
        cout << arr[0];
        return 0;
    }

    int ans1 = solve(arr, 0, n-2); // exclude last
    int ans2 = solve(arr, 1, n-1); // exclude first

    cout << max(ans1 , ans2);

    return 0;
}
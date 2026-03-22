#include<iostream>
#include<vector>
using namespace std;

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
    int prev2 = 0;
    int prev = arr[0];
    for(int i=1; i<n; i++){
        
        int pick = arr[i];
        if(i > 1) pick += prev2;
        int notPick = prev;

        int curr = max(pick , notPick);
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
    
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    int prev2=0;
    int prev=0;
    for(int i=1; i<n; i++){
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = 1e9;
        if(i>1){
            ss = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curr = min(fs , ss);
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
    
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prev2 = 0;
    int prev = 1;

    if(n==0){
        cout << 0;
        return 0;
    }
    if(n==1){
        cout << 1;
        return 0;
    }

    for(int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << prev;
    
    return 0;
}
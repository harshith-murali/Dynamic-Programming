#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int prev2 = 0 , prev1 = 1, curr;
    if(n == 0) {
        cout<<prev2<<endl;
        return 0;
    }
    if(n == 1) {
        cout<<prev1<<endl;
        return 0;
    }
    for(int i=2; i<=n; i++){
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<curr<<endl;
}
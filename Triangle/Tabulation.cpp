#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> front = triangle[n-1];

        for(int i = n-2; i >= 0; i--){
            vector<int> curr(i+1);

            for(int j = 0; j <= i; j++){
                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                curr[j] = min(down, diag);
            }

            front = curr;
        }

        return front[0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << sol.minimumTotal(triangle);
    return 0;
}
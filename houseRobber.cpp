#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        int prev = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int take = nums[i] + prev2;
            int notTake = prev;
            int curri = max(take, notTake);

            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

    int rob(vector<int>& money) {
        int n = money.size();
        if (n == 1) return money[0];

        vector<int> temp1, temp2;

        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(money[i]);      // exclude first
            if (i != n - 1) temp2.push_back(money[i]); // exclude last
        }

        return max(nonAdjacent(temp1), nonAdjacent(temp2));
    }
};

int main() {
    Solution sol;

    vector<int> money = {2, 3, 2};
    cout << "Maximum money robbed: " << sol.rob(money) << endl;

    return 0;
}
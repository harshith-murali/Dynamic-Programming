#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int prev2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int temp = max(prev, nums[i] + prev2);
            prev2 = prev;
            prev = temp;
        }
        return prev;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum money robbed: " << sol.rob(nums) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int money : nums) {
            int curr = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << s.rob(nums);
    return 0;
}
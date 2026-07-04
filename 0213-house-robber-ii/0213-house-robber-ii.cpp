class Solution {
public:
    int rob2(vector<int>& nums) {
        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for (int money : nums) {
            int curr = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        vector<int> first(nums.begin(),nums.end()-1);
        vector<int> second(nums.begin()+1,nums.end());

        return max(rob2(first),rob2(second));
    }
};
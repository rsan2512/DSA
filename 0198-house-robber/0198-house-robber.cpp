class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev,prev2,curr;
        prev = nums[0];
        prev2 = 0;

        for(int i = 1;i<n;i++){
            int take = nums[i]+ prev2;

            int nottake = 0+prev;

            curr = max(take,nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
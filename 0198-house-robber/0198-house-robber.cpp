class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp,int n){
        if(n<0)return 0;  // if n becomes smaller than 0 arr ended 
        
        if(n==0) return nums[0];  // last num
        
        if(dp[n]!=-1) return dp[n];  //memoization

        int pick = solve(nums,dp,n-2)+nums[n];  //picking curr house and skipping next one (n-2)
        int notp = solve(nums,dp,n-1); // skipping current house 

        return dp[n]=max(pick,notp); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);

        int ans = solve(nums,dp,n-1);

        return ans;
    }
};
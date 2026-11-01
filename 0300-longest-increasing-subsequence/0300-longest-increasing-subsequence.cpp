class Solution {
public:
    int fn(int i, int prev_i,vector<int>& nums,vector<vector<int>>& dp ){
        if(i==nums.size()) return 0; // base

        if( dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
        int notpick = 0+ fn(i+1,prev_i,nums,dp); // not pick
        int pick =0;
        if(prev_i == -1 || nums[i] > nums[prev_i]){ 
            pick = 1 + fn(i+1,i,nums,dp);  //pick
        }
        return dp[i][prev_i+1]=max(notpick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fn(0,-1,nums,dp);
    }
};
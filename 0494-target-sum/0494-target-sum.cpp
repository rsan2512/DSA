class Solution {
public:
    int fn(int n, int tar,int sum, vector<int>& arr, vector<vector<int>>& dp,int offset){
        if(n<0){
            if(tar == sum) return 1;
            else return 0;
        }
        if(dp[n][sum+offset]!=-1) return dp[n][sum+offset];
        int l= fn(n-1,tar,sum+ arr[n],arr,dp,offset);
        int r= fn(n-1 ,tar, sum-arr[n],arr,dp,offset);
        return dp[n][sum+offset]= l+r;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum+sum+1,-1));
        return fn(n-1,target,0,nums,dp,sum);
    }
};
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
        // vector<vector<int>> dp(n+1,vector<int>(n+2,0));
        //return fn(0,-1,nums,dp);
        // for(int i =n-1;i>=0;i--){
        //     for(int j =i-1; j>=-1;j--){
        //         int notpick = 0+dp[i+1][j+1]; // not pick
        //         int pick =0;
        //         if(j == -1 || nums[i] > nums[j])
        //             pick = 1 + dp[i+1][i+1];  //pick
        //         dp[i][j+1]=max(notpick,pick);
        //     }
        // }return dp[0][0];
        // vector<int> dp(n,1);
        // int maxi =1;
        // for(int i =0;i<n;i++){
        //     for(int j =0;j<i;j++){
        //         if(nums[i]>nums[j])
        //             dp[i]=max(1+dp[j],dp[i]);
        //     }maxi = max(dp[i],maxi);
        // }return maxi;
        vector<int> temp;
        int len =1;
        temp.push_back(nums[0]);
        for(int i =1;i<n;i++){
            if(nums[i]>temp.back()){  
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }return len;
    }
};
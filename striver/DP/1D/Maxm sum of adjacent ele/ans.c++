#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums,vector<int>& dp,int n){
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];

        int pick = solve(nums,dp,n-2)+ nums[n];

        int Ntpick= solve(nums,dp,n-1);

        return max(pick,Ntpick);
    }
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n-1);
    }
};

int main(){
    Solution obj;
    vector<int> nums = {2,1,4,5,3,2,6};
    cout<<obj.nonAdjacent(nums);
}
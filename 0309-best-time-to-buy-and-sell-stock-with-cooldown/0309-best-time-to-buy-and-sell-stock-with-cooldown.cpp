class Solution {
public:
    int fun(int i,int j,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==1){
            return dp[i][j]= max(fun(i+1,0,prices,dp)-prices[i],fun(i+1,1,prices,dp));
        }else{
            return dp[i][j]= max(fun(i+2,1,prices,dp)+prices[i],fun(i+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,1,prices,dp);
    }
};
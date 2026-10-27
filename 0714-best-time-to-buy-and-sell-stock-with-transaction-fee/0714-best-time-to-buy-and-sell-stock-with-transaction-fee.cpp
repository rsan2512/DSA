class Solution {
public:
    int fun(int i,int j,vector<int>& prices,int fee,vector<vector<int>>& dp){
        if(i==prices.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==1){
            return dp[i][j]=max(fun(i+1,0,prices,fee,dp)-prices[i],fun(i+1,1,prices,fee,dp));
        }else{
            return dp[i][j]=max(fun(i+1,1,prices,fee,dp)+prices[i]-fee,fun(i+1,0,prices,fee,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,1,prices,fee,dp);
    }
};
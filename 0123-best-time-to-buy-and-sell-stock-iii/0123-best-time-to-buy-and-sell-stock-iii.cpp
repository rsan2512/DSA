class Solution {
public:
    int fun(int i,int buy,int cap,vector<vector<vector<int>>>& dp,vector<int>& prices){
        if(i==prices.size() || cap ==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap] = max(fun(i+1,0,cap,dp,prices)-prices[i], fun(i+1,1,cap,dp,prices));
        }else{
            return dp[i][buy][cap] = max(fun(i+1,1,cap-1,dp,prices)+prices[i], fun(i+1,0,cap,dp,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(0,1,2,dp,prices);
    }
};
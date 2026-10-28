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
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        //return fun(0,1,prices,dp);
        for(int i =n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j==1){
                    dp[i][j]= max(dp[i+1][0]-prices[i],dp[i+1][1]);
                }else{
                    dp[i][j]= max(dp[i+2][1]+prices[i],dp[i+1][0]);
                }
            }
        }return  dp[0][1];
    }
};
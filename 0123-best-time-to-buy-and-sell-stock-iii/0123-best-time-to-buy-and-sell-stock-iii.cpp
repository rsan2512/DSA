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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //return fun(0,1,2,dp,prices);
        //the base cases are aleready 0
        //for(i=0->n)for(buy=0->1) dp[i][buy][0] = 0;
        //for(buy=0->1)for(cap=0->2) dp[n][buy][cap] = 0;
        for(int i =n-1;i>=0;i--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                   if(buy){
                      dp[i][buy][cap] = max(dp[i+1][0][cap] - prices[i], dp[i+1][1][cap]);
                    }else{
                      dp[i][buy][cap] = max(dp[i+1][1][cap-1]+prices[i], dp[i+1][0][cap]);
                    }
                }
            }
        }return dp[0][1][2];
    }
};
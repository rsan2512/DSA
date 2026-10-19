class Solution {
public:
    int fun(int i,int buy,vector<vector<int>> &dp,vector<int> &prices){
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return  dp[i][buy];
        int profit =0;
        if(buy){  //to buy or not buy
            profit = max(fun(i+1,0,dp,prices)-prices[i] , fun(i+1,1,dp,prices)-0);
        }else{  //to sell or not sell
            profit = max(fun(i+1,1,dp,prices)+prices[i] , fun(i+1,0,dp,prices)+0);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        dp[n][0]=dp[n][1]=0;
        for(int i=n-1; i>=0 ;i-- ){
            for(int buy=0;buy<=1;buy++){
                int profit = 0;
                    if(buy){  //to buy or not buy
                        profit = max(dp[i+1][0] - prices[i] , dp[i+1][1]);
                    }else{  //to sell or not sell
                        profit = max(dp[i+1][1] + prices[i] , dp[i+1][0]);
                    }
                    dp[i][buy] = profit;
                        }
        } 
        return dp[0][1];
        //return fun(0,1,dp,prices);
    }
};
class Solution {
public:
    int fun(int i,int j,int k,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size() || j==k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j%2 == 0){  //buy in even
            return dp[i][j]= max(-prices[i]+fun(i+1,j+1,k,prices,dp),fun(i+1,j,k,prices,dp));
        }
        else{
            return dp[i][j]= max(+prices[i]+fun(i+1,j+1,k,prices,dp),fun(i+1,j,k,prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = k*2;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        //return fun(0,0,k*2,prices,dp);
        // base case already 0 
        for(int i =n-1;i>=0;i--){   //bottom up approach
            for(int j=k-1;j>=0;j--){
                if(j%2 == 0){
                    dp[i][j]= max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
                }
                else{
                    dp[i][j]= max(+prices[i]+dp[i+1][j+1],dp[i+1][j]);
                }
            }
        }return dp[0][0];
    }
};
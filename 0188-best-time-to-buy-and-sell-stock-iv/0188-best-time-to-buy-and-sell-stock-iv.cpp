class Solution {
public:
    int fun(int i,int j,int k,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size() || j==k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(j%2 == 0){
            return dp[i][j]= max(-prices[i]+fun(i+1,j+1,k,prices,dp),fun(i+1,j,k,prices,dp));
        }
        else{
            return dp[i][j]= max(+prices[i]+fun(i+1,j+1,k,prices,dp),fun(i+1,j,k,prices,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(k*2,-1));
        return fun(0,0,k*2,prices,dp);
    }
};
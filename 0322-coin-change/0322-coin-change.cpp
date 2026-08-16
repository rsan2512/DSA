class Solution {
public:
    int fun(vector<int>& coins,int amt,vector<int>& dp){
        dp[0] = 0;
        
        int minsteps =INT_MAX;
        for(int j =1;j<=amt;j++){
            int minsteps =INT_MAX;
            for(int i =0;i<coins.size();i++){
                if(coins[i]<=j){
                    int cstep =dp[j-coins[i]];
                    if(cstep != INT_MAX) {
                        minsteps = min(minsteps, cstep + 1);
                    }
                }
            }dp[j]=minsteps;
        }
        return dp[amt];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount ==0)return 0;
        int n = coins.size();
        vector<int> dp(amount+1,-1);
        int ans = fun(coins,amount,dp);
        if(ans == INT_MAX)return -1;
        else return ans;
    }
};
class Solution {
public:
    int fun(vector<int>& coins,int amt,vector<int>& dp){
        if(amt == 0 ) return 0;
        if(amt<0) return INT_MAX;

        if(dp[amt]!=-1) return dp[amt];

        int minsteps =INT_MAX;
        for(int i =0;i<coins.size();i++){
            if(coins[i]<=amt){
                int cstep =fun(coins,amt-coins[i],dp);
                if(cstep != INT_MAX) {
                    minsteps = min(minsteps, cstep + 1);
                }
            }
        }
        return dp[amt]=minsteps;
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
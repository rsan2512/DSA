class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& dp ){
        for(int i = 0 ; i<m;i++){
            for(int j = 0; j<n ; j++){
                if(i ==0 && j ==0 ) dp[0][0] =1;
                else{
                    int up = 0,left =0;
                    if(i-1>=0) up= dp[i-1][j];
                    if(j-1>=0) left= dp[i][j-1];
                    dp[i][j] = left + up;
                }
            }
        }return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        return solve(m,n,dp);
    }
};
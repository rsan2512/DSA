class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& dp, vector<vector<int>>& grid ){
        for(int i =0;i<m ;i++){
            for(int j = 0;j<n;j++){
                if(i==0 && j ==0) dp[i][j]=1;
                else if(grid[i][j]==1) dp[i][j] = 0;
                else{
                    int up =0,left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up+left;
                }
            }
        }return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size();
        int n = Grid[0].size();
        if(Grid[m-1][n-1]==1) return 0;
        if(Grid[0][0]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        return solve(m,n,dp,Grid);
    }
};
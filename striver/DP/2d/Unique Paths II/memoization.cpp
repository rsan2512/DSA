#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dp, vector<vector<int>>& grid ){
        if(grid[i][j] == 1) return 0;  // if current cell is blocked
        if(i == 0 && j == 0) return 1;  // base case
        if(dp[i][j]!=-1) return dp[i][j];
        int l =0, u =0;

        if(i-1>=0) l = solve(i-1,j,dp,grid);
        if(j-1>=0) u = solve(i,j-1,dp,grid);

        return dp[i][j]=l + u;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size();
        int n = Grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,Grid);
    }
};

int main(){
    Solution obj;
    vector<vector<int>> Grid = {{0,0,0},
                                 {0,1,0},
                                 {0,0,0}};
    cout<<obj.uniquePathsWithObstacles(Grid);
}
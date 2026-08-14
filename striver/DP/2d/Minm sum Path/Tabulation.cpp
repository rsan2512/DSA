#include <bits/stdc++.h>
using namespace std;

// T.c = O(m*n) and S.c = O(m*n) for dp array

// This is a tabulation approach to find the minimum path sum in a grid.
// The function `solve` iteratively fills the dp array with the minimum path sums to reach
// each cell from the top-left corner (0, 0).
// The base case is when we reach the starting cell, where we set its value to the
// corresponding value in the grid. For each cell, we calculate the minimum path sum
// by considering the minimum of the path sums from the cell above and the cell to the left
// and adding the current cell's value. Finally, we return the value in the bottom-right
// cell of the dp array, which represents the minimum path sum to reach that cell.

class Solution {
public:
    int solve(int m , int n , vector<vector<int>>& grid,vector<vector<int>>& dp){
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i ==0 & j==0) dp[i][j]= grid[i][j];
                else{
                    int up = INT_MAX,left=INT_MAX;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(up,left);
                }
            }
        }return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m,n,grid,dp);
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {{1,3,1},
                                 {1,5,1},
                                 {4,2,1}};
    cout<<obj.minPathSum(grid);
}
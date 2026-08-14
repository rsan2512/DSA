#include  <bits/stdc++.h>
using namespace std;

// T.c = O(m*n) and S.c = O(m*n) + O(m+n) for recursion stack

// This is a memoization approach to find the minimum path sum in a grid.
// The function `solve` recursively calculates the minimum path sum to reach the cell (m, n) from the top-left corner (0, 0). 
//It checks if the current cell is already computed in the dp array to avoid redundant calculations. 
//The base case is when we reach the starting cell, where we return its value. 
//The function explores two possible paths: moving up or moving left, and returns the minimum 
//of these two paths added to the current cell's value.
//The main function initializes the dp array and calls the solve function for the bottom-right cell of the grid.
class Solution {
public:
    int solve(int m , int n , vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(m == 0 && n == 0 ) return grid[0][0];

        if(dp[m][n]!=-1) return dp[m][n];

        int up = INT_MAX,left =INT_MAX;
        if(m>0) up = grid[m][n] + solve(m-1,n,grid,dp);
        if(n>0) left = grid[m][n] + solve(m,n-1,grid,dp);

        return dp[m][n]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {{1,3,1},
                                 {1,5,1},
                                 {4,2,1}};
    cout<<obj.minPathSum(grid);
}
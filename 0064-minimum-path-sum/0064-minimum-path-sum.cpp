class Solution {
public:
    int solve(int m , int n , vector<vector<int>>& grid,vector<int>& prev){
        for(int i =0;i<m;i++){
            vector<int> curr(n,0);
            for(int j = 0;j<n;j++){
                if(i ==0 && j==0) curr[j]= grid[i][j];
                else{
                    int up = INT_MAX,left=INT_MAX;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = grid[i][j] + min(up,left);
                }
            }swap(prev,curr);
        }return prev[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,INT_MAX);
        return solve(m,n,grid,dp);
    }
};
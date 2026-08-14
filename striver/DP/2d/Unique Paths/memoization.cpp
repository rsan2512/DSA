#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& dp ){
        if(i == 0 && j == 0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int l =0, r =0;

        if(i-1>=0) l = solve(i-1,j,dp);
        if(j-1>=0) r = solve(i,j-1,dp);

        return dp[i][j]=l + r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};

int main(){
    int m,n;
    m = 3;
    n= 7;
    Solution obj;
    cout<<obj.uniquePaths(m,n);
}
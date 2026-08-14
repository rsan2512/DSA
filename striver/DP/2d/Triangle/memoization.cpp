#include <bits/stdc++.h>
using namespace std;

// T.c = O(m*n) and S.c = O(m*n) for dp array

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& tri,vector<vector<int>>& dp){
        if(i==tri.size()-1) return dp[i][j] = tri[i][j];

        if(dp[i][j]!=-100) return dp[i][j];
        int d = tri[i][j]+ solve(i+1,j,tri,dp);
        int dr= tri[i][j]+ solve(i+1,j+1,tri,dp);
        return dp[i][j] =min(d,dr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-100));
        return solve(0,0,triangle,dp);
    }
};

int main(){
    Solution obj;
    vector<vector<int>> triangle = {{2},
                                    {3,4},
                                    {6,5,7},
                                    {4,1,8,3}};
    cout<<obj.minimumTotal(triangle);
}
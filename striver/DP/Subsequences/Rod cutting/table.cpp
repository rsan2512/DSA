#include <bits/stdc++.h>
using namespace std;

// Rod Cutting Problem - Tabulation
// Time Complexity: O(N*N)
// Space Complexity: O(N*N)

class Solution {
  public:
    int fn(int N,vector<int>& price,int i,vector<vector<int>>& dp){
        for(int i= 1;i<=N;i++){
            for(int j= 1;j<=N;j++){
                    int ntake = dp[i][j-1];
                    int take = 0;
                    if(j<=i) take = dp[i-j][j]+ price[j-1];
        
                    dp[i][j]=max(ntake,take);
            }
        }return dp[N][N];
    }
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return fn(n,price,n,dp);
    }
};

int main(){
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << sol.cutRod(price) << endl;   // ans: 22
    return 0;
}
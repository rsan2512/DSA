#include <bits/stdc++.h>
using namespace std;

// Rod Cutting Problem - Memoization
// Time Complexity: O(N*N)
// Space Complexity: O(N*N) + O(N) for recursion stack


class Solution {
  public:
    int fn(int N,vector<int>& price,int i,vector<vector<int>>& dp){
        if(i<=0 || N<=0) return 0;
        
        if(dp[N][i]!=-1) return dp[N][i];
        int ntake = fn(N,price,i-1,dp);
        int take = 0;
        if(N>=i) take = fn(N-i,price,i,dp) + price[i-1];
        
        return dp[N][i]=max(ntake,take);
        
    }
    
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fn(n,price,n,dp);
    }
};

int main(){
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << sol.cutRod(price) << endl;   // ans: 22
    return 0;
}
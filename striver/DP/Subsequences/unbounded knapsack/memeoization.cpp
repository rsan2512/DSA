#include <bits/stdc++.h>
using namespace std;

// Unbounded Knapsack Problem
//Time Complexity: O(N*W)
// Space Complexity: O(N*W)
class Solution {
  public:
    int fn(int W,int n,vector<int>& val, vector<int>& wt,vector<vector<int>>& dp){
        if(W<=0) return 0;
        if(n<0) return 0;
        
        if(dp[n][W]!=-1) return dp[n][W];
        
        int ntake= fn(W,n-1,val,wt,dp);
        int take = 0;
        if(wt[n] <= W)
            take = fn(W-wt[n],n,val,wt,dp)+val[n];
        
        return max(take,ntake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n =  wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return fn(capacity,n-1,val,wt,dp);
    }
};

int main(){
    Solution sol;
    vector<int> val = {10, 20, 30};
    vector<int> wt = {1, 2, 3};
    int capacity = 5;
    cout << sol.knapSack(val, wt, capacity) << endl;   // ans: 50
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Unbounded Knapsack Problem - Tabulation
//Time Complexity: O(N*W)
// Space Complexity: O(N*W)

class Solution {
  public:
    int fn(int W,int n,vector<int>& val, vector<int>& wt,vector<vector<int>>& dp){
        for(int j = 0;j<=W;j++){    //ALT :  dp[0][j] = dp[0][j - wt[0]] + val[0];
            if(wt[0]<=j){
                dp[0][j] = (j/wt[0])*val[0];
            }
        }
        
        for(int i = 1;i<n;i++){
            for(int j = 0;j<=W;j++){
                int ntake= dp[i-1][j];
                int take = 0;
                if(wt[i] <= j )
                    take = dp[i][j-wt[i]]+val[i];
            dp[i][j]= max(take,ntake);
            }
        }
        return dp[n-1][W];
    }
        
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n =  wt.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        return fn(capacity,n,val,wt,dp);
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
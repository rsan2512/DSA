#include <bits/stdc++.h>
using namespace std;

// t.c = O(n*sum) s.c = O(n*sum)
class Solution {
  public:
  
    bool fun(int n,int tar, vector<int>& arr,vector<vector<int>>& dp){
        if(tar == 0) return true;
        if(n==0) return(tar == arr[0]);
        if(dp[n][tar]!=-1) return dp[n][tar];
        
        bool ntake = fun(n-1,tar,arr,dp);
        bool take = false;
        if(arr[n]<=tar)
            take = fun(n-1,tar - arr[n],arr,dp);
        
        return dp[n][tar]=take or ntake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum + 1,-1));
        return fun(n-1,sum,arr,dp);
        
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1,2,3,4};
    int sum = 6;
    cout<<obj.isSubsetSum(arr,sum);
}
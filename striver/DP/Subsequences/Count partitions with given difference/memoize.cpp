// Count partitions with given difference
// Given an array arr[] of size N and a difference D. The task is to count the number of 
//ways we can partition the array into two subsets such that the difference of the sum of 
//elements in those subsets is equal to D.
// Example 1:
// Input: N = 4, arr[] = {1, 1, 2, 3}, D = 1
// Output: 3
// Explanation: The array can be partitioned as {1, 2} and {1, 3}, {3} and {1, 1, 2}, 
//{1, 3} and {1, 2}.

#include <bits/stdc++.h>
using namespace std;

// t.c = O(n*sum) s.c = O(n*sum)

int mod = (int)(1e9 +7);
class Solution {
  public:
  int countSub(int n,int tar, vector<int>& arr,vector<vector<int>>& dp){
        if(n==0){           // base case
            if(tar ==0 && arr[0]==0) return 2;   // if target is 0 and first element is also 0, we can either take it or not take it, so return 2
             if(tar == 0 || tar == arr[0]) return 1;// if target is 0 or first element is equal to target, we can either take it or not take it, so return 1
            else return 0;
        }
        
        if(dp[n][tar]!=-1) return dp[n][tar];
        
        int ntake = countSub(n-1,tar,arr,dp);
        int take = 0;
        if(arr[n]<=tar)
            take = countSub(n-1,tar - arr[n],arr,dp);
        return dp[n][tar]=(take + ntake)% mod;
    }
   int countPartitions(int n, int diff, vector<int>& arr) {
        int tsum=0;
        for(int i =0;i<n;i++)tsum+=arr[i];

        if(tsum - diff<0 || (tsum-diff) % 2) return 0;  // if target is negative or not an integer, return 0 
        
        int target = (tsum - diff) / 2; // we need to find the number of subsets with sum = target
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return countSub(n-1,target,arr,dp);
    }
};
int main(){
    Solution obj;
    vector<int> arr = {1, 1, 2, 3};
    int diff = 1;
    cout<<obj.countPartitions(arr.size(),diff,arr); // ans = 3
}
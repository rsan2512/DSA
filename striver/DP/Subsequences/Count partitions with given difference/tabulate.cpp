#include <bits/stdc++.h>
using namespace std;

// T.c = O(n*sum) s.c = O(n*sum)
int mod = (int)(1e9 +7);
class Solution {
  public:
  int countSub(int n,int tar, vector<int>& arr,vector<vector<int>>& dp){
        if(arr[0] == 0) dp[0][0] =2;  // if first element is 0, we can either take it or not take it, so return 2
        else dp[0][0]=1;

        if(arr[0]!=0 && arr[0]<=tar) dp[0][arr[0]] =1;  // if first element is not 0 and less than or equal to target, we can either take it or not take it, so return 1
        
        for(int i =1;i<n;i++){
            for(int j = 0;j<=tar;j++){
                int ntake = dp[i-1][j];
                int take = 0;
                if(arr[i]<=j)
                    take = dp[i-1][j - arr[i]];
                 dp[i][j]=(take + ntake)% mod;
            }
        }
        return dp[n-1][tar];
    }
   int countPartitions(int n, int diff, vector<int>& arr) {
        int tsum=0;
        for(int i =0;i<n;i++)tsum+=arr[i];
        if(tsum - diff<0 || (tsum-diff) % 2) return 0;
        int target = (tsum - diff) / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        return countSub(n,target,arr,dp);
    }
};
int main(){
    Solution obj;
    vector<int> arr = {1,2,3,4};
    int diff = 2;
    cout<<obj.countPartitions(arr.size(),diff,arr); // 
}
 
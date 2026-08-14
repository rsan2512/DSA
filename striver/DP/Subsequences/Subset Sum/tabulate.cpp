#include <bits/stdc++.h>
using namespace std;

// t.c = O(n*sum) s.c = O(n*sum)

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum + 1,0));
        
        for(int i =0 ; i<n;i++){
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        
        for(int i = 1;i<n;i++){
            for(int tar = 1;tar<=sum;tar++){
                bool notTake = dp[i-1][tar];
                
                bool take = false;
                if(arr[i]<= tar) take = dp[i-1][tar-arr[i]];
                
                dp[i][tar]= take | notTake;
            }
        }
        return dp[n-1][sum];
    }
};

int main(){
    Solution obj;
    vector<int> arr = {1,2,3,4};
    int sum = 6;
    cout<<obj.isSubsetSum(arr,sum);
}
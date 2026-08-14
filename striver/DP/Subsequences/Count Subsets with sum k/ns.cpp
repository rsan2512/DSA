#include <bits/stdc++.h>
using namespace std;

// t.c = O(n*sum) s.c = O(n*sum)

// Logic behind this: We are counting the number of ways to achieve the target sum using 
//the elements of the array. At each element, we have two choices: either include it in 
//the subset or exclude it. We recursively explore both possibilities and sum up the number
// of valid subsets.

class Solution{
	public:
    int sub(int n,int tar, vector<int>& arr,vector<vector<int>>& dp){
        if(tar == 0) return 1;
        if(n==0){
            if(tar ==0 && arr[0]==0) return 2;
            if(tar == arr[0]) return 1;
            else return 0;
        }
        
        if(dp[n][tar]!=-1) return dp[n][tar];
        
        int ntake = sub(n-1,tar,arr,dp);
        int take = 0;
        if(arr[n]<=tar)
            take = sub(n-1,tar - arr[n],arr,dp);
        return dp[n][tar]=take + ntake;
    }
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(K+1,-1));
        return sub(n-1,K,arr,dp);
	}
};

int main(){
    Solution obj;
    vector<int> arr = {1,2,3,4};
    int sum = 6;
    cout<<obj.perfectSum(arr,sum);
}
#include <bits/stdc++.h>
using namespace std;

// t.c = O(n*sum) s.c = O(n*sum)
// only works for non-negative numbers


// logic : We want to partition the array into two subsets such that the absolute difference of their sums is minimized.
// This is equivalent to finding a subset with sum as close as possible to half of the total sum.
class Solution {
	public:
	void isSubsetSum(vector<int>& arr, int sum, vector<vector<bool>> & dp) {
		int n = arr.size();
		
		for (int i = 0 ; i<n; i++) {
			dp[i][0] = true;
		}
		if (arr[0] >= 0 && arr[0] <= sum)
			dp[0][arr[0]] = true;
		
		for (int i = 1; i<n; i++) {
			for (int tar = 1; tar <= sum; tar++) {
				bool notTake = dp[i - 1][tar];
				
				bool take = false;
				if (arr[i] <= tar)
					take = dp[i - 1][tar - arr[i]];
				
				dp[i][tar] = take | notTake;
			}
		}
	}
	int minDifference(vector<int>& nums) {
		int totes = 0;
		int n = nums.size();
		for (int i = 0 ; i<n; i++) {
			totes += nums[i];
		}
		vector<vector<bool>> dp(n, vector<bool>(totes + 1, 0));
		isSubsetSum(nums, totes, dp);
		int mini = INT_MAX;
		for (int i = 0; i <= totes/2; i++) {
			if (dp[n - 1][i] == true) {
				int s1 = i;
				int s2 = totes - i;
				mini = min(mini, abs(s1 - s2));
			}
		} return mini;
	}
};

int main() {
    Solution obj;
    vector<int> arr = {1, 7, 3, 5};
    cout << obj.minDifference(arr);
}

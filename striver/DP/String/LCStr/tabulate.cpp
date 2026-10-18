#include <bits/stdc++.h>
using namespace std;

// Longest Common Substring - Tabulation
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)
// Note: The longest common substring is a contiguous sequence of characters that appears in both strings, while the longest common subsequence is a sequence of characters that appears in both strings but not necessarily contiguously.

class Solution{
    public: int longestCommonSubstr (string str1, string str2){
       int n = str1.size();
       int m = str2.size();

       vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
        }
       }
       int maxi = INT_MIN;

        for (int i = 1; i <=n; i++) {
            for (int j = 0; j <=m; j++) {
                maxi = max(maxi, dp[i][j]);
            }
        }

        return maxi;
    }
};

int main(){
    Solution sol;
    string text1 = "abcde";
    string text2 = "acde"; 
    cout << sol.longestCommonSubstr(text1,text2) << endl;   // ans: 3
    return 0;
}
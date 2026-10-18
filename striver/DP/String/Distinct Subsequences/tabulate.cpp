#include <bits/stdc++.h>
using namespace std;    

// Distinct Subsequences - Tabulation
// Time Complexity: O(N*M)


class Solution {
public:

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1,0));
        //return fun(n-1,m-1,dp,s,t);
        for(int i =0;i<=n;i++) dp[i][0] = 1;   // base case using index shift
        // for(int j = 1;j<=m;j++) dp[0][j] =0;   // base case using index shift

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){     // index shift 
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }return (int)dp[n][m];
    }
};

int main(){
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit"; 
    cout << sol.numDistinct(s,t) << endl;   // ans: 3
    return 0;
}
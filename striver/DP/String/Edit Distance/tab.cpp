#include <bits/stdc++.h>
using namespace std;    

// Edit Distance - Tabulation
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

class Solution {
public:
    
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m =s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
       
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j =1;j<=m;j++)dp[0][j] = j;

        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) 
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1+ min(dp[i][j-1], // ins
                            min(dp[i-1][j],  // del
                                dp[i-1][j-1])); //replace
                }
            }
        } 
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                printf("%d ",dp[i][j]);
            }printf("\n");
        }

        return dp[n][m];
    }
};
int main(){
    Solution sol;
    string s1 = "horse";
    string s2 = "ros";
    cout << sol.minDistance(s1,s2) << endl;   // ans: 3
    return 0;
}
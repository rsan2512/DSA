#include <bits/stdc++.h>
using namespace std;

// Edit Distance - Memoization
// Time Complexity: O(N*M)
// Space Complexity: O(N*M) + O(N+M) for recursion stack

class Solution {
public:
    int fun(int i,int j, string &s1,string &s2,vector<vector<int>> &dp){
        if(j==0) return i; // s2 exhaust-> del opn on s1
        if(i==0) return j; // s1 exhaust-> ins opn on s1

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j] = fun(i-1,j-1,s1,s2,dp);
        else{
            return dp[i][j] = 1+ min(fun(i,j-1,s1,s2,dp), // ins
                            min(fun(i-1,j,s1,s2,dp),  // del
                                fun(i-1,j-1,s1,s2,dp))); //replace
        }

    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m =word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int result = fun(n,m,word1,word2,dp);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                printf("%d ",dp[i][j]);
            }printf("\n");
        }
        return result;
    }
};
int main(){
    Solution sol;
    string s1 = "horse";
    string s2 = "ros";
    cout << sol.minDistance(s1,s2) << endl;   // ans: 3
    return 0;
}
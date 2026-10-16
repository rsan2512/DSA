class Solution {
public:
    int fun(int i,int j, string &s1,string &s2,vector<vector<int>> &dp){
        if(j<0) return i+1; // s2 exhaust-> del opn on s1
        if(i<0) return j+1; // s1 exhaust-> ins opn on s1

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] = fun(i-1,j-1,s1,s2,dp);
        else{
            return dp[i][j] = 1+ min(fun(i,j-1,s1,s2,dp), // ins
                            min(fun(i-1,j,s1,s2,dp),  // del
                                fun(i-1,j-1,s1,s2,dp))); //replace
        }

    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m =word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,word1,word2,dp);
    }
};
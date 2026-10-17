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
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m =s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return fun(n-1,m-1,word1,word2,dp);
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
        } return dp[n][m];
    }
};
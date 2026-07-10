class Solution {
public:
    int solve(int m,int n,vector<int>& dp ){
        for(int i = 0 ; i<m;i++){
            vector<int>  temp(n,0);
            for(int j = 0; j<n ; j++){
                if(i ==0 && j ==0) temp[0] =1;
                else{
                    int up = 0,left =0;
                    if(i-1>=0) up= dp[j];
                    if(j-1>=0) left= temp[j-1];
                    temp[j] = left + up;
                }
            }dp = temp;
        }return dp[n-1];
    }
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        return solve(m,n,dp);
    }
};
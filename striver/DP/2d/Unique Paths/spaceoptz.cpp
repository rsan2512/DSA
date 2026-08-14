#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m,int n,vector<int>& dp ){
        for(int i = 0 ; i<m;i++){      // Iterate through each row of the grid
            vector<int>  temp(n,0);             // Create a temporary vector to store the number of unique paths for the current row
            for(int j = 0; j<n ; j++){           // Iterate through each column of the grid
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
        vector<int> dp(n,0);     // (dp or prev arr)Initialize a 1D vector to store the number of unique paths for the previous row
        return solve(m,n,dp);       
    }
};

int main(){
    int m,n;
    m = 3;
    n= 7;
    Solution obj;
    cout<<obj.uniquePaths(m,n);
}
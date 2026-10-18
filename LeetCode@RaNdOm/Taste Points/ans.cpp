#include <bits/stdc++.h>
using namespace std;

int fun(int m,int n,int t,vector<int>& v,vector<int>& d,vector<int>& dp){
    if(m==0) return 0;

    int mint = INT_MAX;
    for(int i =0;i<n;i++){
        int currt= fun(m-1,n,t+v[i]-d[i]*dp[i],v,d,dp);
    }
}
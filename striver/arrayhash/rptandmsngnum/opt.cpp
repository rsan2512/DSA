#include <bits/stdc++.h>
using namespace std;
vector<int> sumtry(vector<int>& nums){
    int n=nums.size();
    long long s1=(long long)n*(n+1)/2;
    long long s2=(long long)n*(2*n+1)*(n+1)/6;

    long sa1=0,sa2=0;
    for(auto x: nums){
        sa1+=x;
        sa2+=(long long)x*x;
    }
    long long x=sa1-s1;
    long long y=sa2-s2;
    long long sum=y/x;
    int rep=(x+sum)/2;
    int miss=rep-x;
    return {rep,miss};
}
main(){
    vector<int> nums={3,5,4,1,1};
    vector<int>  ans=sumtry(nums);
    for(auto x:ans){
        cout<<x<<" ";
    }
}
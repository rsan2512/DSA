#include <bits/stdc++.h>
using namespace std;
int maxsub(vector<int>& arr){
    int n=arr.size();
    int maxsum=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxsum)maxsum=sum;
        if(sum<0){
            sum=0;
        }
    }
    return maxsum;
}
int main(){
    vector<int> ques ={2, 3, 5, -2, 7, -4};
    int ans=maxsub(ques);
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> ques(vector<int> nums){
    int n= nums.size();
    vector<int> ans;
    unordered_map<int,int> freq;
    int lar=INT_MIN,smol=INT_MAX;
    for(int i=0;i<n;i++){
        if(lar<nums[i])lar=nums[i];
        if(smol>nums[i])smol=nums[i];
        freq[nums[i]]++;
    }
    for(auto it:freq){
        if(it.second==2){
            ans.push_back(it.first);
            break;
        }
    }
    for(int i=smol;i<lar;i++){
        if(!freq.count(i)){
            ans.push_back(i);
            break;
        }
    }return ans;
}
int main(){
    vector<int> arr={3,5,4,1,1};
    vector<int> ans=ques(arr);
    for(int x:ans){
        cout<<x<<endl;
    }
}
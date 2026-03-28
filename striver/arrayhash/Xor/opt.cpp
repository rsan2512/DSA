#include <bits/stdc++.h>
using namespace std;
int xorc(vector<int>& nums,int k){
    unordered_map<int,int> freq;
    int prefix=0;
    int count=0;
    for(int i=0;i<nums.size();i++){
        prefix^=nums[i];
        if(prefix==k){
            count++;
        }
        int needed=prefix^k;
        if(freq.find(needed)!=freq.end()){
            count+=freq[needed];
        }
        freq[prefix]++;
    }
    return count;
}
int main(){
    vector<int> nums={4,2,2,6,4};
    int k=6;
    cout << xorc(nums,k);

}
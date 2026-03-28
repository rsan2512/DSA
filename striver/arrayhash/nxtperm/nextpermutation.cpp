#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextpermutation(vector<int> &nums){
    int n= nums.size();
    int i=n-2;
    while(i>=0 && nums[i]>=nums[i+1]){
        i--;
    }
    if(i>=0){
        int j= n-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1,nums.end());
}
int main(){
    cout<< "Enter the array"<<endl;
    vector<int> v(3);
    for(int i=0;i<3;i++){
        cin >> v[i];
    }
    nextpermutation(v);
        for(int x : v) {
        cout << x << " ";
    }
}
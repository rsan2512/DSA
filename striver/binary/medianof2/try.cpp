#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    if(arr1.size()%2==1)return arr1[(arr1.size()/2)];
    else{
        int n=(arr1.size()/2);
        return (double)(arr1[n]+arr1[n-1])/2;
    }    
}

int main() {
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 3, 5};
    
    double median = findMedianSortedArrays(arr1, arr2);
    cout << fixed << setprecision(1) << median << endl;
    
    return 0;
}

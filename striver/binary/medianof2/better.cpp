#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    // Logic goes here
    int n1=arr1.size(),n2=arr2.size();      //size of both arrays
    int n=n1+n2;                            
    
    int ind2=n/2;               //if odd it is the median of both arrays
    int ind1=ind2-1;            //needed if even , both stores the postn of medn for array

    int i=0,j=0,cnt=0;          //pointers i for arr1,j for arr2, cnt for merged array
    int indl1=-1;               //to store element at ind1
    int indl2=-1;               //for ind2

    while(i<n1 && j<n2){            
        if(arr1[i]<arr2[j]){            // same as merge we check for lesser element
            if(cnt==ind1)indl1=arr1[i];         //if at some point count matches the count we store the element value at temp
            if(cnt==ind2)indl2=arr1[i];
            i++;
            cnt++;
        }
        else{
            if(cnt==ind1)indl1=arr2[j];
            if(cnt==ind2)indl2=arr2[j];
            j++;
            cnt++;
        }
    }
    while(i<n1 && cnt <ind2){
        if(cnt==ind1)indl1=arr1[i];
        if(cnt==ind2)indl2=arr1[i];
        i++;
        cnt++;
    }
    while(j<n1 && cnt<ind2){
        if(cnt==ind1)indl1=arr2[i];
        if(cnt==ind2)indl2=arr2[i];
        j++;
        cnt++;
    }
    if(n%2==0){
        return (double)(indl1+indl2)/2;
    }
    else{
        return indl2;
    }

}

int main() {
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 3, 5};
    
    double median = findMedianSortedArrays(arr1, arr2);
    cout << median << endl;
    
    return 0;
}

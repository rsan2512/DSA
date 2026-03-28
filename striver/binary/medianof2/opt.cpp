#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if(a.size()>b.size()) return findMedianSortedArrays(b,a);       //we do bin serach in min len array

    int n1=a.size(), n2 =b.size();
    int low=0,high=n1;      

    while(low<=high){                   //bin search
        int cut1=(high+low)/2;          //cut for a
        int cut2=((n1+n2+1)/2)-cut1;    //cut b
        //boundary condn
        int l1=(cut1==0)?INT_MIN:a[cut1-1];
        int r1=(cut1==n1)?INT_MAX:a[cut1];

        int l2=(cut2==0)?INT_MIN:b[cut2-1];
        int r2=(cut2==n2)?INT_MAX:b[cut2];

        if(l1<=r2 && l2<=r1){
            if((n1+n2)%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else
                return max(l1,l2);
        }
        else if(l1>r2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
    }return 0.0;
}

int main() {
    vector<int> arr1 = {2, 4, 6};
    vector<int> arr2 = {1, 3, 5};
    
    double median = findMedianSortedArrays(arr1, arr2);
    cout << fixed << setprecision(2) << median << endl;
    
    return 0;
}

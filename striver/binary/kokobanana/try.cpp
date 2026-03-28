#include <bits/stdc++.h>
using namespace std;
int test(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            for (int x : piles) {
                hours += (x + mid - 1) / mid;
                if (hours > h) break;
            }

            if (hours <= h) high = mid;
            else low = mid + 1;
        }
        return low;
    }
int main(){
    vector<int> ques={3,6,7,11};
    int h=8;
    int sp=test(ques,h);
    cout<<sp;
}
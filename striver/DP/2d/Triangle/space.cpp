#include <bits/stdc++.h>
using namespace std;

// T.c = O(m*n) and S.c = O(n) for dp array
// This is a space optimized version of the triangle minimum path sum problem.
// The idea is to use a single array to store the minimum path sums for the 
// current row, and update it as we move up the triangle.

class Solution {
public:
    int solve(int m, vector<vector<int>>& tri){
        vector<int> prev(m,0);
        for(int i=0;i<m;i++){     // Initialize the last row of the triangle in the prev array
            prev[i] = tri[m-1][i];
        }
        for(int i = m-2; i>=0;i--){
            vector<int> curr(i+1,0);  // Create a current row array of size i+1
            for(int j =i;j>=0;j--){
                int dw = tri[i][j] + prev[j];
                int dg = tri[i][j] + prev[j+1];
                curr[j] = min(dw,dg); 
            }
            prev = curr;
        }return prev[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        return solve(m,triangle);
    }
};
int main(){
    Solution obj;
    vector<vector<int>> triangle = {{2},
                                    {3,4},
                                    {6,5,7},
                                    {4,1,8,3}};
    cout<<obj.minimumTotal(triangle);
}
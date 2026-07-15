class Solution {
public:
    int solve(int m, vector<vector<int>>& tri){
        vector<int> prev(m,0);
        for(int i=0;i<m;i++){
            prev[i] = tri[m-1][i];
        }
        for(int i = m-2; i>=0;i--){
            vector<int> curr(i+1,0);
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
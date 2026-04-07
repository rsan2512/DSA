#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: store all rotten oranges + count fresh
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;

        // directions: right, left, up, down
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        // Step 2: BFS
        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto [x,y] = q.front();
                q.pop();

                for(int d=0;d<4;d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // check valid and fresh
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2;   // make rotten
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            minutes++; // one level done = 1 minute
        }

        return (fresh==0)? minutes : -1;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int ans = obj.orangesRotting(grid);

    cout << "Minutes required: " << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
    PATH WITH MINIMUM EFFORT
    ------------------------
    Goal:
    Reach bottom-right cell with minimum possible effort.

    Effort of a path =
    maximum absolute height difference
    between consecutive cells.

    We use DIJKSTRA because:
    - We always want the smallest effort first.
    - Priority Queue helps us greedily expand optimal paths.

*/

class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {

        /*
            priority queue stores:
            {effort, {row, col}}

            Smallest effort comes first.
        */
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        int n = heights.size();
        int m = heights[0].size();

        /*
            dist[r][c] =
            minimum effort required to reach cell (r,c)
        */
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // starting point effort is 0
        dist[0][0] = 0;

        // movement directions
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        // start from top-left corner
        pq.push({0, {0,0}});

        while(!pq.empty()) {

            auto [diff, rc] = pq.top();
            pq.pop();

            auto [r, c] = rc;

            /*
                If we reached destination,
                return the answer immediately.

                Dijkstra guarantee:
                first time reaching destination
                = minimum effort
            */
            if(r == n-1 && c == m-1)
                return diff;

            // explore 4 directions
            for(int i = 0; i < 4; i++) {

                int nx = r + dx[i];
                int ny = c + dy[i];

                // boundary check
                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {

                    /*
                        Current step effort:
                        abs(height difference)

                        Total path effort:
                        maximum effort seen so far
                    */
                    int nEffort = max(
                        abs(heights[r][c] - heights[nx][ny]),
                        diff
                    );

                    // found a better path
                    if(nEffort < dist[nx][ny]) {

                        dist[nx][ny] = nEffort;

                        pq.push({nEffort, {nx, ny}});
                    }
                }
            }
        }

        return 0;
    }
};

int main() {

   
    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    Solution obj;

    int ans = obj.minimumEffortPath(heights);

    cout << "Minimum Effort Required = " << ans << endl;



    return 0;
}
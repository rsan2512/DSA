#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(int n, int last,
              vector<vector<int>>& dp,
              vector<vector<int>>& task) {

        if(n == 0) {

            int maxi = 0;

            for(int i = 0; i < 3; i++) {

                if(i != last)
                    maxi = max(maxi, task[0][i]);
            }

            return maxi;
        }

        if(dp[n][last] != -1)
            return dp[n][last];

        int maxi = 0;

        for(int i = 0; i < 3; i++) {

            if(i != last) {

                int points = task[n][i] +
                             solve(n-1, i, dp, task);

                maxi = max(maxi, points);
            }
        }

        return dp[n][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return solve(n-1, 3, dp, matrix);
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    cout << s.ninjaTraining(matrix);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Recursive function with memoization
    // n = current stone index
    int solve(vector<int>& heights, vector<int>& dp, int n) {

        // Base case:
        // If we are already at the first stone,
        // no energy is required.
        if (n == 0)
            return 0;

        // If already computed, return stored answer.
        if (dp[n] != -1)
            return dp[n];

        // Cost of jumping from previous stone (n-1)
        int left = solve(heights, dp, n - 1)
                 + abs(heights[n] - heights[n - 1]);

        // Assume impossible initially.
        int right = INT_MAX;

        // Jump from two stones behind only if it exists.
        if (n - 2 >= 0) {
            right = solve(heights, dp, n - 2)
                  + abs(heights[n] - heights[n - 2]);
        }

        // Store and return the minimum cost.
        return dp[n] = min(left, right);
    }

    int frogJump(vector<int>& heights) {

        int n = heights.size();

        // dp[i] = minimum energy needed to reach stone i
        vector<int> dp(n, -1);

        // Start solving from the last stone.
        return solve(heights, dp, n - 1);
    }
};

int main() {

    // Heights of stones
    vector<int> heights = {30, 10, 60, 10, 60, 50};

    Solution obj;

    cout << "Minimum Energy = "
         << obj.frogJump(heights);

    return 0;
}
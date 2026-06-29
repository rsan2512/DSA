#include <bits/stdc++.h>
using namespace std;


// Problem

// A frog starts at stone 0 and wants to reach the last stone.

// If the frog jumps from stone i to stone j, the energy spent is

// |height[i] - height[j]|

// The frog can jump at most k stones at a time.

// Find the minimum total energy.
class Solution {
public:
    int solve(vector<int>& heights, vector<int>& dp, int k, int n) {

        // Base case
        if (n == 0)
            return 0;

        // Memoization
        if (dp[n] != -1)
            return dp[n];

        int minimum = INT_MAX;

        // Try every jump from 1 to k
        for (int i = 1; i <= k; i++) {

            // Check if previous stone exists
            if (n - i >= 0) {

                int temp = solve(heights, dp, k, n - i)
                         + abs(heights[n] - heights[n - i]);

                minimum = min(minimum, temp);
            }
        }

        return dp[n] = minimum;
    }

    int frogJump(vector<int>& heights, int k) {

        int n = heights.size();

        vector<int> dp(n, -1);

        return solve(heights, dp, k, n - 1);
    }
};

int main() {

    int n, k;

    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> heights(n);

    cout << "Enter heights:\n";

    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << "Enter maximum jump (k): ";
    cin >> k;

    Solution obj;

    cout << "Minimum Energy = " << obj.frogJump(heights, k);

    return 0;
}
// Enter number of stones: 3
// Enter heights:
// 20 15 13
// Enter maximum jump (k): 3
// Minimum Energy = 7
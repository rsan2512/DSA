
class Solution {
public:
    bool fun(int i, int j, string &s, string &p,
             vector<vector<int>> &dp) {

        if (i == 0 && j == 0) return true;
        if (j == 0) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (i == 0) {
            return dp[i][j] =
                (p[j - 1] == '*' && fun(i, j - 1, s, p, dp));
        }

        if (p[j - 1] == '*') {
            return dp[i][j] =
                fun(i - 1, j, s, p, dp) ||
                fun(i, j - 1, s, p, dp);
        }

        if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
            return dp[i][j] =
                fun(i - 1, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return fun(n, m, s, p, dp);
    }
};

class Solution
{
public:
    int f(int i, int j, string t1, string t2, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        // if both the string are equal
        if (t1[i] == t2[j])
            return 1 + f(i, j, t1, t2, dp);
        // if not
        return dp[i][j] = max(f(i - 1, j, t1, t2, dp), f(i, j - 1, t1, t2, dp));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, text1, text2, dp);
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string &text1, string &text2, int m, int n, int memo[][1001])
    {
        if (m == 0 || n == 0)
        {
            return 0;
        }
        if (memo[m][n] != -1)
        {
            return memo[m][n];
        }
        if (text1[m - 1] == text2[n - 1])
        {
            return memo[m][n] = 1 + longestCommonSubsequence(text1, text2, m - 1, n - 1, memo);
        }
        else
        {
            return memo[m][n] = max(longestCommonSubsequence(text1, text2, m - 1, n, memo), longestCommonSubsequence(text1, text2, m, n - 1, memo));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        int memo[1001][1001];
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                memo[i][j] = -1;
            }
        }
        return longestCommonSubsequence(text1, text2, m, n, memo);
    }
};
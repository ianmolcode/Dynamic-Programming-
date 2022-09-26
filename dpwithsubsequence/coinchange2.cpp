class Solution
{
public:
    int f(int n, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return (amount % coins[0] == 0);
        }
        if (dp[n][amount] != -1)
            return dp[n][amount];
        int nt = f(n - 1, amount, coins, dp);
        int t = 0;
        if (coins[n] <= amount)
        {
            t = f(n, amount - coins[n], coins, dp);
        }
        return dp[n][amount] = t + nt;
    }
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};
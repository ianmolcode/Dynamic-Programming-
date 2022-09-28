class Solution
{
public:
    int recursive(int i, vector<int> &coins, int n, int amount, vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            if (amount % coins[i] == 0)
                return amount / coins[i];
            else
                return 1e9;
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int notTake = recursive(i - 1, coins, n, amount, dp);
        int take = INT_MAX;
        if (coins[i] <= amount)
        {
            take = 1 + recursive(i, coins, n, amount - coins[i], dp);
        }
        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = recursive(n - 1, coins, n, amount, dp);
        if (res == 1e9)
            return -1;
        else
            return res;
    }
};
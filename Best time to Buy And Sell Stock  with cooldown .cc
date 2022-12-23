class Solution
{
public:
    int dp[5010][2];
    int func(int i, vector<int> &prices, int flag)
    {
        if (i >= prices.size())
            return 0;
        if (dp[i][flag] != -1)
            return dp[i][flag];
        int ans = 0;
        ans = max(ans, func(i + 1, prices, flag));
        if (flag == 1)
            ans = max(ans, func(i + 2, prices, 0) + prices[i]);
        else
            ans = max(ans, func(i + 1, prices, 1) - prices[i]);
        return dp[i][flag] = ans;
    }
    int maxProfit(vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        return func(0, prices, 0);
    }
};

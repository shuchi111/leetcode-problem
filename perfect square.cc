class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i=2; i<=n; ++i) {
            for(int x=1; x*x<=i; ++x) {
                int tmp = 1 + dp[i-x*x];
                dp[i] = min(dp[i], tmp);
            }
        }
        
        return dp[n];
    }
};

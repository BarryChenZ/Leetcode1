//參考
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tmax = 2, size = prices.size();
        if(size < 2) return 0;
        vector<vector<int>> dp(tmax+1, vector<int>(size, 0));
        for(int i = 1; i <= tmax; ++i) {
            int maxMoney = -prices[0];
            for(int j = 1; j < size; ++j) {
                maxMoney = max(maxMoney, -prices[j] + dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j] + maxMoney);
            }
        }   
        return dp[tmax][size-1];
    }
};

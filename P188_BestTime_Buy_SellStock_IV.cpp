class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int tmax = k, size = prices.size();
        if(tmax >= size/2) {
            int sum = 0;
            for(int i = 1; i < size; ++i) sum += max(0, prices[i] - prices[i-1]);
            return sum;
        }
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

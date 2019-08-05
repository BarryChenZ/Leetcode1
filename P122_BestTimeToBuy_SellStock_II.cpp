class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int currentMax = -1;
        for( int i = prices.size() - 1; i >= 0; i-- ) {
            currentMax = max( currentMax, prices[i] );
            if( prices[i] < currentMax ) {
                profit = profit + ( currentMax - prices[i] );
                // reset the current max as it gets utilized
                currentMax = prices[i];
            }
        }
        return profit;
    }
};

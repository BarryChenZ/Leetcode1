class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int res = 0;
        int maxi = 0;
        int k = prices.size();
        for(int i = 0; i < k; i++){
            int temp = prices[i];
            //int temp_days = i;
            for(int j = i + 1; j < k; j++){
                if(prices[j] > temp){
                    temp = prices[j];
                    //temp_days = j;
                }
            }
            if(temp - prices[i] > maxi){
                //cout << temp_days << i << endl;
                maxi = temp - prices[i];
                //res = temp_days - i;
            }
        }
        return maxi;
    }
};

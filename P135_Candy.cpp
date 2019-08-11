class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        int frontcount[n + 1];
        int peak = 1;
        frontcount[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i - 1] < ratings[i]) peak++;
            else peak = 1;
            frontcount[i] = peak;
        }
        
        int backcount[n + 1];
        peak = 1;
        backcount[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i + 1] < ratings[i]) peak++;
            else peak = 1;
            backcount[i] = peak;
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            count += max(frontcount[i], backcount[i]);
        }
        return count;
    }
};

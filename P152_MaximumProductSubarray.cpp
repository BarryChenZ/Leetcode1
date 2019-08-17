class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        // 0 : cut // < 0 : save // > 0 : update
        if(n == 1) return nums[0];
        int m = nums[0];
        int M = nums[0];
        vector<int> vM;
        vM.push_back(M);
        int trueMax = INT_MIN;
        for(int i = 1; i < n; i++){
            
            int ma = m * nums[i];
            int mb = M * nums[i];
            m = min(min(ma, mb), nums[i]);
            M = max(max(ma, mb), nums[i]);
            vM.push_back(M);
            
        }
        
        for (auto e : vM) trueMax = max(e, trueMax);
        
        return trueMax;
    }
};

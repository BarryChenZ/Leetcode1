class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size();){
            int tmp = nums[i] - nums[i - 1];
            if(tmp > res) res = tmp;
            i++;
            while(i < nums.size()) {
                if(nums[i - 1] == nums[i]) i++;
                else break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int large = 1;
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        int repeat = 0;
        sort(nums.begin(), nums.end());
        if(nums.size() < 1) return res;
        int temp = nums[0];
        res = 1;
        for(int i = 1; i < nums.size(); i++){
            if(abs(nums[i] - temp) > 1){
                if(res - repeat > large) large = res - repeat;
                repeat = 0;
                res = 0;
            }
            if(abs(nums[i] - temp) == 0){
                repeat++;
            }
            temp = nums[i];
            res++;
        }
        if(res - repeat > large) large = res-repeat;
        return large;
    }
};

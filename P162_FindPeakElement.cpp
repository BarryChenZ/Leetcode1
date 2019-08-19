class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int res;
        int n = nums.size();
        if(n == 1) return 0;
        for(int i = 0; i < n; i++){
            res = i;
            if(i == 0){
                if(nums[i] > nums[i+1]) break;
            }
            else if(i == nums.size() - 1){
                 if(nums[i] > nums[i-1]) break;
            }
            else{
                if(nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) break;
            }
        }
        return res;
    }
};

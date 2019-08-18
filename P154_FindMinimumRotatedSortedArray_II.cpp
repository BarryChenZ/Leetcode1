class Solution {
public:
    int findMin(vector<int>& nums) {
       int res = 0;
        if(nums.size() == 1 || nums[nums.size() - 1] > nums[0]) return nums[0];
        res = nums[0];
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]) {
                res = nums[i + 1];
                break;
            }
        }
        return res;
    } 
};

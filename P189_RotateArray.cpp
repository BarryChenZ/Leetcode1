class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0) return;
        int j = k % nums.size();
        for(int i = 0; i < j ;i++){
            int temp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), temp);
        } 
        return;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        if(n < 1) return res;
        int counter = 0;
        sort(nums.begin(), nums.end());
        int temp = nums[0];
        bool finded = false;
        for(int i = 0; i < nums.size(); i++){
            if(temp == nums[i]){
                counter++;
            }
            else{
                if(counter <= 1){
                    res = temp;
                    finded = true;
                    break;
                }
                counter = 1;
            }
            temp = nums[i];   
        }
        if(counter <= 1 && finded == false) res = nums[nums.size() - 1];
        return res;
    }
};

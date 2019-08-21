class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i = 0; i < numbers.size(); i++){
            res.push_back(i + 1);
            int tmp = target - numbers[i];
            if(find(numbers.begin() + i, numbers.end(), tmp) != numbers.end()){
                res.push_back(find(numbers.begin() + i + 1, numbers.end(), tmp) - numbers.begin() + 1);
                break;
            }
            else res.pop_back();
            while(i + 1 < numbers.size()){
                if(numbers[i + 1] == numbers[i]) i++;
                else break;
            }
        }
        return res;
    }
};

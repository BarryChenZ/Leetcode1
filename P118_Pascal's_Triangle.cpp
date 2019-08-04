class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int k = 2;
        vector<vector<int>> res;
        if(numRows == 0) return res;
        vector<int> temp1;
        temp1.push_back(1);
        res.push_back(temp1);
        while(k <= numRows){
            vector<int> temp2;
            for(int i = 1; i <= k; i++){
                if(i == 1 || i == k) temp2.push_back(1);
                else temp2.push_back(res[k - 2][i - 2] + res[k - 2][i - 1]);
            }
            res.push_back(temp2);
            k++;
        }
        return res;
    }
};

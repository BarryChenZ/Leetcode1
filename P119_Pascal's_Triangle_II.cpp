class Solution {
public:
    vector<int> getRow(int rowIndex) {
     int k = 2;
        vector<vector<int>> res;
        vector<int> temp1;
        temp1.push_back(1);
        res.push_back(temp1);
        while(k <= rowIndex + 1){
            vector<int> temp2;
            for(int i = 1; i <= k; i++){
                if(i == 1 || i == k) temp2.push_back(1);
                else temp2.push_back(res[k - 2][i - 2] + res[k - 2][i - 1]);
            }
            res.push_back(temp2);
            if(k == rowIndex + 1) return temp2;
            k++;
        }
        return temp1;
    }
};

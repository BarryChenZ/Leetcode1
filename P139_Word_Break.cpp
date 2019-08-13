class Solution {
public:
    bool res = false;
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> strset;
        strset.insert(wordDict.begin(), wordDict.end());
        vector<bool> check(n + 1, 0);
        check[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j <= n; j++){
                if(check[j] == 1){
                    if(strset.find(s.substr(i, j - i)) != strset.end()){
                        check[i] = 1;
                        break;
                    }
                }
            }
        }
        return check[0];
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        generate(s, res, 0, {});
        return res;
    }
    void generate(string s, vector<vector<string>>& res , int idx, vector<string> temp){
        if(idx == s.size()){
            res.push_back(temp);
            return;
        }
        string tmp;
        for(int i = idx; i < s.size(); i++){
            tmp += s[i];
            if(isPalin(tmp)){
                temp.push_back(tmp);
                generate(s, res, i + 1, temp);
                temp.pop_back();
            }
        }
    }
    bool isPalin(string tmp){
        int i = 0;
        int j = tmp.size() - 1;
        while(i <= j){
            if(tmp[i++] != tmp[j--]) return false;
        }
        return true;
    }
};

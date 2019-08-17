class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        if(size == 0) return s;
        vector<string> temp;
        string res;
        find(s, temp);
        for(int i = temp.size() - 1; i >= 0; i--){
            res += temp[i];
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
    void find(string s, vector<string>& temp){
        string tmp;
        bool start = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                tmp += s[i];
                start = true;
            }
            else{
                if(start == true){
                    temp.push_back(tmp);
                    start = false;
                    tmp.clear();
                }
            }
        }
        if(start == true) temp.push_back(tmp);
    }
};

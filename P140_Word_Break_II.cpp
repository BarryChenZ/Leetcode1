class Solution {
public:
    unordered_map<int,vector<string>> cache;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        return check(s, dict, 0);
    }
    vector<string> check(string& s, unordered_set<string>& dict, int idx){
        if(idx >= s.size()){
            vector<string> out;
            out.push_back("");
            return out;
        }
        if(cache.find(idx) == cache.end()){
            string temp;
            cache[idx] = vector<string>();
            for(int i = idx; i < s.size(); i++){
                temp += s[i];
                if(dict.find(temp) != dict.end()){
                    vector<string> sub = check(s, dict, i + 1);
                    for(int j = 0; j < sub.size(); j++){
                        sub[j] = sub[j] == "" ? temp : temp + ' ' + sub[j];
                        cache[idx].push_back(sub[j]);
                    }
                }
            }
        }
        return (cache[idx]);
    }
};

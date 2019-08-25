class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> m;
        for(int i = 0; i < s.size(); i++){
            string temp = s.substr(i, 10);
            if(m[temp] == 1){
                ans.push_back(temp);
            }
            m[temp]++;
        }
        return ans;
    }
};

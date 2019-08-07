//參考
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s;
        for(string p: wordList) s.insert(p);
        
        queue< pair<string, int> >q; // {string, dist in number of updates from beginWord}
        q.push({beginWord, 1});
        
        while(!q.empty()) {
            pair<string, int> p = q.front();
            string cur = p.first;
            q.pop();
            if(cur == endWord) { // we have reached the target
                return p.second; // return the dist in terms of number of changes from beginWord
            }
            for(int i = 0; i < cur.size(); i++) {
                for(char c = 'a'; c <= 'z'; c++) {
                    char temp = cur[i];
                    if(cur[i] != c) cur[i] = c;
                    if(s.find(cur) != s.end()) {
                        q.push({cur, p.second + 1}); // 1 jump more from current word to reach here
                        s.erase(cur); // word is processed, remove it from dictionary
                    }
                    cur[i] = temp;
                }
            }
        }
        return 0;
    }
};

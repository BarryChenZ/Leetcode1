class Solution {
public:
    int res = INT_MAX;
    int minCut(string s) {
        vector<int> dp(s.size() + 1, 0);
        for(int i = 0; i <= s.size(); i++) dp[i] = i - 1;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; i-j >= 0 && i+j < s.size() && s[i+j] == s[i-j]; ++j)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);
            
            for(int j = 0; i-j-1 >= 0 && i+j < s.size() && s[i+j] == s[i-j-1]; ++j)
                dp[i+j+1] = min(dp[i+j+1], dp[i-j-1]+1);
        }
        return dp[s.size()];
    }
};

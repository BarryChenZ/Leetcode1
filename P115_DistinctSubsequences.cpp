class Solution {
public:
    int res = 0;
    int numDistinct(string s, string t) {
        if(s.size()==0 || t.size()==0) return 0;
        vector<vector<long long>> dp(t.length()+1,vector<long long>(s.length()+1,0));
        dp[0][0]=1;
        for(int i=0;i<=t.length();i++){
           for(int j=1;j<=s.length();j++){
              if(i==0) dp[0][j]=1;
              else if(t[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
              else dp[i][j]=dp[i][j-1];
          }
      }
        return dp[t.length()][s.length()];
    }
};

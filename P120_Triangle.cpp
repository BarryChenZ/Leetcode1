class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int k = triangle.size();
        int res = INT_MAX;
        if( k == 1) return triangle[0][0];
        
        for(int i = 1; i < k; i++){
            int n = triangle[i].size();
            for(int j = 0; j < n; j++){
                if( j == 0)       triangle[i][j] += triangle[i - 1][j];
                else if ( j == i) triangle[i][j] += triangle[i - 1][j - 1];
                else              triangle[i][j] += min(triangle[i - 1][j],triangle[i - 1][j - 1]);
            }
        }
        
        for(int i = 0; i < k; i++) res = min(res, triangle[k - 1][i]);
        return res;
    }
};

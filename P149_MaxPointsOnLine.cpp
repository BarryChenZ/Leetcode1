class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        if(n <= 1) return n;
        double slope;
        
        for(int i = 0; i < n; i++){
            unordered_map<double, int> tmp;
            int sameCount = 0;
            int maxCount = 0;
            for(int j = 0; j != i && j < n; j++){
                if(points[i] == points[j]) sameCount++;
                else{
                    int count = ++tmp[sloper(points[i], points[j])];
                    maxCount = max(count, maxCount);
                }
            }
            maxCount += sameCount;
            res = max(res, maxCount);
        }
        
        return res + 1;
    }
    
    double sloper(vector<int>&p1, vector<int>&p2) {
		if (p1[0] == p2[0])
			return DBL_MAX;
		return ((double)p1[1] - p2[1]) / (p1[0] - p2[0]);
	}
};

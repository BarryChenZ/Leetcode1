class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int aHeight = dungeon.size();
        if (aHeight <= 0) { return 0; }
        
        int aWidth = dungeon[0].size();
        if (aWidth <= 0) { return 0; }
        
        int aHealth[aHeight][aWidth];
        
        aHealth[aHeight-1][aWidth-1] = max(1, 1-dungeon[aHeight-1][aWidth-1]);
        
        for (int i=aWidth-2;i>=0;i--) {
            aHealth[aHeight-1][i] = max(1, aHealth[aHeight-1][i+1] - dungeon[aHeight-1][i]);
        }
        
        for (int n=aHeight-2;n>=0;n--) {
            aHealth[n][aWidth-1] = max(1, aHealth[n+1][aWidth-1] - dungeon[n][aWidth-1]);
        }
        
        int aChoice1, aChoice2, aSmallChoice;
        for (int i=aWidth-2;i>=0;i--) {
            for (int n=aHeight-2;n>=0;n--) {
                aChoice1 = aHealth[n][i + 1];
                aChoice2 = aHealth[n + 1][i];
                aSmallChoice = min(aChoice1, aChoice2) - dungeon[n][i];
                aHealth[n][i] = max(1, aSmallChoice);
            }
        }
        
        return aHealth[0][0];  
    }
};

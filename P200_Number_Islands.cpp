    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    if(traced(grid, row, col, i, j)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
    bool traced(vector<vector<char>>& grid, int row, int col, int i, int j){
        if(i >= row or j >= col or i < 0 or j < 0) return true;
        if(grid[i][j] == '0') return true;
        grid[i][j] = '0';
        
        bool l = traced(grid, row, col, i - 1, j);
        bool r = traced(grid, row, col, i + 1, j);
        bool u = traced(grid, row, col, i, j + 1);
        bool d = traced(grid, row, col, i, j - 1);
        return l && r && u && d;
    }
};

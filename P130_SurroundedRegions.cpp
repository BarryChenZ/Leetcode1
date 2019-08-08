class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n <= 1) return;
        int m = board[0].size();
        if(m <= 1) return;
        for (int i = 0; i< board.size(); ++i)
            for (int j = 0; j< board[0].size(); ++j) {
                if (i > 0 && i < board.size()-1 && j > 0 && j < board[0].size()-1)
                    continue;
                if (board[i][j] == 'O')
                    search(i, j, board);
            }
        
        for (int i=0; i<board.size(); ++i)
            for (int j=0; j<board[0].size(); ++j)
                if (board[i][j] == '1')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X'; 
        
        return;
    }
    void search(int i, int j, vector<vector<char>>& board){
        if(board[i][j] != 'O')  return;
        
        board[i][j] = '1';
        
        if(i < board.size() - 1) search(i + 1, j, board);
        if(i > 0) search(i - 1, j, board);
        if(j < board[0].size() - 1) search(i, j + 1, board);
        if(j > 0) search(i, j - 1, board);
        
        return;
    }
};

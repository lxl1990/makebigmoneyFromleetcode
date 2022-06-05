class TicTacToe {
private:
    std::vector<vector<int>> horizontal;
    std::vector<vector<int>> vertical;
    std::vector<vector<int>> diagonal;
    int size;
public:
    TicTacToe(int n): size(n) {
        horizontal = vector<vector<int>>(2, vector<int>(n, 0));
        vertical = vector<vector<int>>(2, vector<int>(n, 0));
        diagonal = vector<vector<int>>(2, vector<int>(2, 0));
    }
    
    int move(int row, int col, int player) {
        if (++horizontal[player - 1][row] == size) return player;
        if (++vertical[player - 1][col] == size) return player;
        if (row == col && ++diagonal[player - 1][0] == size) return player;
        if (row + col == size - 1 && ++diagonal[player - 1][1] == size) return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

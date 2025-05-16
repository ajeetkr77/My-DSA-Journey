class Solution {
public:
    bool isValidPosition(vector<string> &board, int row, int col, int n){

        // Valid upward direction

        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q') return false;
        }

        // valid right diagonal direction

        int i = row - 1, j = col + 1;

        while(i >= 0 && j < n){
            if(board[i][j] == 'Q') return false;
            i--, j++;
        }

        // valid left diagonal direction

        i = row - 1, j = col - 1;

        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--, j--;
        }

        return true;
            
    }

    void solve(vector<string> &board, int row, vector<vector<string>> &result, int n){
        if(row >= n){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){

            if(isValidPosition(board, row, col, n)){
                board[row][col] = 'Q';

                solve(board, row + 1, result, n);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;

        solve(board, 0, result, n);

        return result;
    }
};

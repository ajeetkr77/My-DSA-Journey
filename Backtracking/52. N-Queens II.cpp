class Solution {
public:
    void solve( vector<string> &board, int row, int n, unordered_set<int> &cols, unordered_set<int> &diags
            ,unordered_set<int> &antiDiags, int &ans ){
        if(row == n){
            ans++;
            return;
        }

        for(int col = 0; col < n; col++){
            int diag = row - col;
            int antiDiag = row + col;

            if(cols.find(col) != cols.end() || diags.find(diag) != diags.end() ||
                antiDiags.find(antiDiag) != antiDiags.end())
                continue;
            
            cols.insert(col);
            diags.insert(diag);
            antiDiags.insert(antiDiag);
            board[row][col] = 'Q';

            solve(board, row + 1, n, cols, diags, antiDiags, ans);

            cols.erase(col);
            diags.erase(diag);
            antiDiags.erase(antiDiag);
            board[row][col] = '.';
        }

    }

    int totalNQueens(int n) {
        
        vector<string> board(n, string(n, '.'));

        unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antiDiags;
        int ans = 0;

        solve(board, 0, n, cols, diags, antiDiags, ans);

        return ans;

    }

};

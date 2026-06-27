class Solution {
public:
void dfs(vector<vector<char>> &board, int n, int m, int i, int j){
    board[i][j] = '#';
    int dr[] = {0,1,-1,0};
    int dc[] = {1,0,0,-1};
    for(int k=0; k<4; k++){
        int newr = i + dr[k];
        int newc = j + dc[k];

        if(newr>=0 && newr<n && newc>=0 && newc<m){
            if(board[newr][newc] == 'O') dfs(board, n, m, newr, newc);
        }
    }
    return;
}
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<m; i++){
            if(board[0][i] == 'O') dfs(board,n, m, 0, i);
            if(board[n-1][i] == 'O') dfs(board, n, m, n-1, i);
        }

        for(int i=0; i<n; i++){
            if(board[i][0]=='O') dfs(board, n, m, i, 0);
            if(board[i][m-1] == 'O') dfs(board, n, m, i, m-1);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool rows[9][10]={}, cols[9][10]={}, box[9][10]={};

    int boxid(int a, int b){ return (a/3)*3 + b/3; }

    bool helper(vector<vector<char>>& board, int a, int b){
        if(a==9) return true;

        int nextr=(b==8)?a+1:a;
        int nextc=(b==8)?0:b+1;

        // skip pre-filled
        if(board[a][b]!='.') return helper(board,nextr,nextc);

        for(int k=1;k<=9;k++){
            if(!rows[a][k] && !cols[b][k] && !box[boxid(a,b)][k]){
                rows[a][k]=cols[b][k]=box[boxid(a,b)][k]=true;
                board[a][b]='0'+k;
                if(helper(board,nextr,nextc)) return true;
                board[a][b]='.';
                rows[a][k]=cols[b][k]=box[boxid(a,b)][k]=false;
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialize from pre-filled cells
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.'){
                    int d=board[i][j]-'0';
                    rows[i][d]=cols[j][d]=box[boxid(i,j)][d]=true;
                }
        helper(board,0,0);
    }
};

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution sol;
    sol.solveSudoku(board);

    // print solved board
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j];
            if(j%3==2) cout<<" ";  // box separator
        }
        cout<<"\n";
        if(i%3==2) cout<<"\n";    // box separator
    }
    return 0;
}



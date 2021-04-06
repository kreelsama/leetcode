#include<algorithm>
#include<vector>
using namespace std;

int tryouts = 0;

class Solution {
public:
    bool choices_row[9][9] {true};
    bool choices_col[9][9] {true};
    bool choices_box[9][9] {true};
    // bool intersection[9] {false};

    int getBoxNum(int row, int col){
        return (row/3)*3 + (col/3);
    }

    void intersect(bool row[9], bool col[9], bool box[9], bool intersection[9]){
        for(int i = 0; i < 9; ++i){
            if(row[i] && col[i] && box[i]){
                intersection[i] = true;
            }
        }
    }

    bool solve(vector<vector<char>>& board, int row, int col){
        if(row > 8){
            row = 0;
            col += 1;
        }
        if(col > 8){
            return true;
        }

        // Do not solve for given positions
        if(board[row][col] != '.'){
            return solve(board, row+1, col);
        }

        int boxnum = getBoxNum(row, col);

        //check available choices
        bool intersection[9]{false};
        intersect(choices_row[row], choices_col[col],choices_box[boxnum], intersection);

        for(int sel = 1; sel <= 9; sel++){
            if(intersection[sel - 1]){
                // try for one choice
                board[row][col] = sel + '0';

                choices_row[row][sel - 1] = 0;
                choices_col[col][sel - 1] = 0;
                choices_box[boxnum][sel - 1]= 0;
                tryouts += 1;
                bool res = solve(board, row+1, col);
                if(res){
                    return true;
                }

                // failed, back to unsolved station
                board[row][col] = '.';
                choices_row[row][sel - 1] = 1;
                choices_col[col][sel - 1] = 1;
                choices_box[boxnum][sel - 1]= 1;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // initialization
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                choices_row[i][j] = 1;
                choices_col[i][j] = 1;
                choices_box[i][j] = 1;
            }
        }

        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    choices_row[i][board[i][j] - '0' - 1] = 0;
                    choices_col[j][board[i][j] - '0' - 1] = 0;
                    choices_box[getBoxNum(i, j)][board[i][j] - '0' - 1] = 0;
                }
            }
        }
        solve(board, 0, 0);
    }

};
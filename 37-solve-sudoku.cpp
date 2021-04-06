#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;

int tryouts = 0;

class Solution {
public:
    vector<bitset<9>> choices_row = vector<bitset<9>>(9, bitset<9>("111111111"));
    vector<bitset<9>> choices_col = vector<bitset<9>>(9, bitset<9>("111111111"));
    vector<bitset<9>> choices_box = vector<bitset<9>>(9, bitset<9>("111111111"));
    // bool choices_row[9][9] {true};
    // bool choices_col[9][9] {true};
    // bool choices_box[9][9] {true};
    // bool intersection[9] {false};

    int getBoxNum(int row, int col){
        return (row/3)*3 + (col/3);
    }

    void intersect(const bitset<9>& row, const bitset<9>& col, const bitset<9>& box, bitset<9>& intersection){
        intersection = row & col & box;
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
        bitset<9> intersection;
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
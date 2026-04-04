#if  0

//9、Valid Sudoku

#include <vector>
#include <string>
#include <array>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<int, 10>, 10> a, b, c;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (isdigit(board[i][j])) {//判断是否是数字
                    int num = board[i][j] - '0';
					int k = i / 3 * 3 + j / 3;//9宫格索引
                    if (++a[i][num] == 2 || ++b[j][num] == 2 || ++c[k][num] == 2) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
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
    bool res = sol.isValidSudoku(board);
    cout << "res:" << res;
    return 0;
}

#endif
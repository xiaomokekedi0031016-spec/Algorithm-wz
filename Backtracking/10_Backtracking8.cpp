//10、N皇后
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        // 初始化棋盘：n行n列，全为 '.'
        vector<string> board(n, string(n, '.'));
        // 三个集合：记录不能放皇后的位置
        unordered_set<int> col_set;   // 列：col
        unordered_set<int> add_set;   // 主对角线（/）：row + col
        unordered_set<int> sub_set;   // 副对角线（\）：row - col

        dfs(res, col_set, add_set, sub_set, n, 0, board);
        return res;
    }
	//res: 存储结果的二维字符串数组
	// col_set: 存储已经被占用的列索引
	// add_set: 存储已经被占用的主对角线索引（row + col）
	// sub_set: 存储已经被占用的副对角线索引（row - col）
    // n: 棋盘的大小
	// row: 当前正在处理的行索引
	// board: 当前棋盘的状态，使用字符串数组表示，每个字符串代表一行
    void dfs(vector<vector<string>>& res,
        unordered_set<int>& col_set,
        unordered_set<int>& add_set,
        unordered_set<int>& sub_set,
        int n, int row,
        vector<string>& board) {
        // 递归终止条件：已经放完n行，说明找到一个合法解
        if (row == n) {
            res.push_back(board);
            return;
        }

        // 遍历当前行的每一列，尝试放皇后
        for (int col = 0; col < n; ++col) {
            // 剪枝：如果当前列/主对角线/副对角线已经有皇后，直接跳过
            if (col_set.count(col) || add_set.count(row + col) || sub_set.count(row - col)) {
                continue;
            }

            // 标记：当前位置放皇后，记录占用的列、对角线
            col_set.emplace(col);
            add_set.emplace(row + col);
            sub_set.emplace(row - col);
            board[row][col] = 'Q';

            // 递归：去下一行放皇后
            dfs(res, col_set, add_set, sub_set, n, row + 1, board);

            // 回溯：撤销标记，恢复棋盘，尝试下一列
            col_set.erase(col);
            add_set.erase(row + col);
            sub_set.erase(row - col);
            board[row][col] = '.';
        }
    }
};
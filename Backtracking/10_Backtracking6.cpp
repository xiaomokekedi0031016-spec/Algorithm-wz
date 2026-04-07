#if 0 
//6、单词搜索
#include <vector>
#include <string>
using namespace std;
/*
输入：board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']], word = "ABCCED"
输出：true
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        // 记录每个格子是否被访问过
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));

        // 遍历矩阵的每一个格子，作为DFS的起点
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (dfs(board, word, row, col, 0, visit)) {
                    return true;
                }
            }
        }
        // 所有起点都试过了，没找到
        return false;
    }
	//row: 当前行 col: 当前列 
    //index: word对于的索引(当前匹配到单词的哪个位置了)
	//visit: 记录当前单元格是否已经被访问过了
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index, vector<vector<bool>>& visit) {
        if (index == word.size()) {
            return true;
        }
		int rows = board.size();//行
        int cols = board[0].size();//列
        if(row>=rows || col>=cols || row<0 || col<0 || visit[row][col] || board[row][col] != word[index]) {
            return false;
		}
        visit[row][col] = true;

        bool res = false;

        res |= dfs(board, word, row + 1, col, index + 1, visit);
        res |= dfs(board, word, row - 1, col, index + 1, visit);
        res |= dfs(board, word, row, col + 1, index + 1, visit);
        res |= dfs(board, word, row, col - 1, index + 1, visit);

        visit[row][col] = false;

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    printf("%d\n", s.exist(board, word));
	return 0;
}
#endif

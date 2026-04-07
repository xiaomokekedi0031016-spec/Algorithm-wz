#if 0
#include <string>
#include <vector>
using namespace std;
//5、括号生成
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		string tmp;
		dfs(n, 0, 0, tmp, res);
		return res;
    }
	//n: 需要生成的括号对数 left: 已经生成的左括号数量 right: 已经生成的右括号数量
    //tmp: 当前生成的字符串 res: 最终结果集
    void dfs(int n, int left, int right, string& tmp, vector<string>& res) {
		if (left == n && right == n) {
			res.push_back(tmp);
			return;
		}
		if (left < n) {
			tmp.push_back('(');
			dfs(n, left + 1, right, tmp, res);
			tmp.pop_back();
		}
		if (right < left) {
			tmp.push_back(')');
			dfs(n, left, right + 1, tmp, res);
			tmp.pop_back();
		}
    }
};

int main() {
	Solution s;

	for(auto str : s.generateParenthesis(3)) {
		printf("%s\n", str.c_str());
	}

	return 0;
}	

#endif

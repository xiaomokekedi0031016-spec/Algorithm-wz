#if 0 

#include <vector>
#include <string>
using namespace std;
//7、回文分割
class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> tmp;
		dfs(s, 0, res, tmp);
		return res;
    }

    void dfs(string s, int index, vector<vector<string>>& res, vector<string>& tmp) {
		if (index >= s.size()) {
			res.emplace_back(tmp);
			return;
		}
		for (int i = index; i < s.size(); ++i) {
			if (isPalindrome(s, index, i)) {
				tmp.emplace_back(s.substr(index, i - index + 1));
				dfs(s, i + 1, res, tmp);
				tmp.pop_back();
			}
		}
    }

	//回文数
	bool isPalindrome(string s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			++left;
			--right;
		}
		return true;
	}
};

int main() {
	Solution s;
	string str = "aab";
	for (auto vec : s.partition(str)) {
		for (auto str : vec) {
			printf("%s ", str.c_str());
		}
		printf("\n");
	}
	return 0;
}

#endif

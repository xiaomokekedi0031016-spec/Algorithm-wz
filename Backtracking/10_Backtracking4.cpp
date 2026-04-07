#if 0 

#include <vector>
using namespace std;
//4、组合总和
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> tmp;
		help(candidates, target, 0, res, tmp);
		return res;
    }
	//candidates：原数组；target：目标和；start：搜索数组从第几个元素开始；res：结果集；tmp：当前组合
    void help(vector<int>& candidates, int target, int start, vector<vector<int>>& res, vector<int>& tmp) {
        if(target == 0) {
            res.push_back(tmp);
            return;
		}
        for (int i = start; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
				tmp.push_back(candidates[i]);
				help(candidates, target - candidates[i], i, res, tmp);
				tmp.pop_back();
            }
        }
    }
};

int main() {
	Solution s;
	vector<int> candidates = { 2,3,6,7 };
	int target = 7;
	vector<vector<int>> res = s.combinationSum(candidates, target);
	for(auto &v : res) {
		for(auto &i : v) {
			printf("%d ", i);
		}
		printf("\n");
	}

	return 0;
}

#endif
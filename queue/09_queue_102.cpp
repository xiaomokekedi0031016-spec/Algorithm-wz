//二叉树层次遍历

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> Q;
		if (root) {
			Q.push(root);
		}

		vector<vector<int>> ans;
		
		while (!Q.empty()) {
			//生成新的一层(vector<int>)
			ans.emplace_back();
			//ans.push_back(vector<int>());
			int qSize = Q.size();
			while (qSize--) {
				//取出当前层的一个节点(顺序)
				auto cur = Q.front();
				Q.pop();
				//把当前层的节点值放入当前层的vector<int>中
				ans.back().push_back(cur->val);
				//把当前层的节点的左右子树加入队列中
				if (cur->left) {
					Q.push(cur->left);
				}
				if (cur->right) {
					Q.push(cur->right);
				}
			}
		}
		return ans;
	}
};

int main09() {
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution sol;
	vector<vector<int>> ans = sol.levelOrder(root);
	for (const auto& level : ans) {
		for (int val : level) {
			cout << val << " ";
		}
		cout << endl;
	}
	
	return 0;
}
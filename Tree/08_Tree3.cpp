#if 0 
//3、Diameter of Binary Tree
//计算二叉树的直径
//给定一棵二叉树，返回树的直径长度。二叉树的直径长度是树中任意两个节点路径长度中的最大值。这条路径可能穿过根节点。
/*
        1
         \
          2
         / \
        3   4
         \    \
          5    6
*/
#include "08_Tree.h"
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);//防止被覆盖
        return 1 + max(left, right);
    }
};

int main() {
	Solution sol;
	TreeNode* root = nullptr;
	root = insert(root, 1);
	insert(root, 2);
	insert(root, 3);
	insert(root, 4);
	insert(root, 5);
	cout << "二叉树的直径长度是:" << sol.diameterOfBinaryTree(root) << endl;


    return 0;
}

#endif

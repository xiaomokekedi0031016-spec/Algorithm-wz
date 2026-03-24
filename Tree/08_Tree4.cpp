#if 0 
//4、Balanced Binary Tree
#include "08_Tree.h"
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//对于这个问题，平衡二叉树的定义是：一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1。

/*
        1
       / \
      2   2
     /     \
    3       3
   /         \
  4           4
*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
		return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 2);
    insert(root, 3);
    insert(root, 3);
    insert(root, 4);
    insert(root, 4);
    Solution sol;
    cout << "二叉树是否是平衡二叉树:" << (sol.isBalanced(root) ? "是" : "否") << endl;
    return 0;
}
#endif

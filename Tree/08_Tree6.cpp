#if 0

//6、Subtree of Another Tree
//判断一个树是否是另一个树的子树
//给你两棵二叉树的根节点 root 和 subRoot 。检查 root 中是否存在一个子树与 subRoot 的结构和节点值完全相同。如果存在，返回 true ；否则，返回 false 。
//树 root 的一个子树包括 root 的一个节点和这个节点的所有子孙。树 subRoot 也可以看做是 root 的一个子树。
//示例 1：
/*
      3                
     / \
    4   5
   / \
  1   2
       \
        0

    4
   / \
  1   2           false

    4
   / \
  1   2
       \
        0         true
*/

#include "08_Tree.h"
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (!subRoot) return true;
        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (root && subRoot && root->val == subRoot->val) {
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        }
        else {
            return false;
        }
    }
};

int main() {
	Solution sol;
	TreeNode* root = nullptr;
	root = insert(root, 3);
	insert(root, 4);
	insert(root, 5);
	insert(root, 1);
	insert(root, 2);

    TreeNode* root1 = nullptr;
    root1 = insert(root1, 3);
    insert(root1, 4);
    insert(root1, 5);
    insert(root1, 1);
    insert(root1, 2);

	cout << sol.isSubtree(root, root1) << endl; 

    return 0;
}
#endif

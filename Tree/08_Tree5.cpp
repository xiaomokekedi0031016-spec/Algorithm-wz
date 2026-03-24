#if 0 

#include "08_Tree.h"
//5、Same Tree
//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检查这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
//示例 1：
//Input: p = [1, 2, 3], q = [1, 2, 3]
//Output : true
//示例 2：
//Input: p = [1, 2], q = [1, null, 2]
//Output : false
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)return true;
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else {
            return false;
        }
    }
};

int main() {
    Solution sol;
    TreeNode* root = nullptr;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);

    TreeNode* root1 = nullptr;
    root1 = insert(root1, 1);
    insert(root1, 2);
    insert(root1, 3);

    cout << sol.isSameTree(root, root1);

    return 0;
}

#endif

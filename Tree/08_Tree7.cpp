#if 0
//7、Lowest Common Ancestor in Binary Search Tree
//给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
//在树中，节点 p 和 q 的最近公共祖先是指一个节点 x，满足 x 是 p 和 q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。

/*
        6
       / \
      2   8
     / \  / \
    0   4 7  9
       / \
      3   5            
    
	3和5的最近公共祖先是4
	2和4的最近公共祖先是2
*/

#include "08_Tree.h"
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* curr = root;
        while (curr) {
            if (curr->val < p->val && curr->val < q->val) {
                curr = curr->right;
            }
            else if (curr->val > p->val && curr->val > q->val)
            {
                curr = curr->left;
            }
            else {
                return curr;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    TreeNode* root = nullptr;
	root = insert(root, 6);
	insert(root, 2);
	insert(root, 8);
	insert(root, 0);
	insert(root, 4);
	insert(root, 7);
	insert(root, 9);
    insert(root, 3);
    insert(root, 5);

	TreeNode* p = search(root, 3);
	TreeNode* q = search(root, 5);
	TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

	if (lca) {
		cout << "最近公共祖先是: " << lca->val << endl;
	}
    else {
        cout << "没有找到公共祖先" << endl;
    }

    return 0;
}
#endif
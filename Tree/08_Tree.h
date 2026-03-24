#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {
    }
};

//二叉树插入操作
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
		return new TreeNode(val);
    }
	TreeNode* curr = root;//当前节点
	TreeNode* parent = nullptr;//父节点
    while (curr) {
		parent = curr;  
        if (val < curr->val) {
			curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
    if (val < parent->val) {
        parent->left = new TreeNode(val);
    }
    else {
        parent->right = new TreeNode(val);
	}
    return root;
}

//二叉树的搜索
TreeNode* search(TreeNode* root, int val) {
	TreeNode* curr = root;  
    while (curr) {
        if (val == curr->val) {
            return curr;
        }
        else if (val < curr->val) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
	return nullptr;
}

/*
      1
     / \
    2   3
   / \
  4   5          
  前序遍历：1 2 4 5 3  根节点 -> 左子树 -> 右子树
  中序遍历：4 2 5 1 3  左子树 -> 根节点 -> 右子树
  后序遍历：4 5 2 3 1  左子树 -> 右子树 -> 根节点
  层次遍历：1 2 3 4 5  根节点 -> 每层从左到右
*/

//二叉树的前序遍历
void preorder(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> st;
	st.push(root);
    while (!st.empty()) {
		TreeNode* cur = st.top();
		cout << cur->val << " ";
        st.pop();
        if (cur->right) {
			st.push(cur->right);
        }
        if (cur->left) {
            st.push(cur->left);
        }
    }
}

void preorder1(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

//二叉树的中序遍历
void inorder(TreeNode* root) {
    stack<TreeNode*> st;
	TreeNode* cur = root;
    while (!st.empty() || cur) {
        while (cur) {
			st.push(cur);  
			cur = cur->left;
        }
		cur = st.top();
        st.pop();
        cout << cur->val << " ";
		cur = cur->right;
    }
}

void inorder1(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

//二叉树的后序遍历
void postorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* cur = st1.top(); st1.pop();
        st2.push(cur);

        if (cur->left) st1.push(cur->left);
        if (cur->right) st1.push(cur->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->val << " ";
        st2.pop();
    }
}


void postorder1(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

//二叉树的层次遍历
void levelOrder(TreeNode* root) {
	queue<TreeNode*> q; 
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
	}
}

//释放内存
void destroy(TreeNode* root) {
    if (root == nullptr) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}
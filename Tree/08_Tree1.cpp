#if 0
#pragma once	
#include <iostream>
#include <stack>
#include <queue>
#include "08_Tree.h"

#if 0
//test
int main() {
	TreeNode* root = nullptr;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 7);
	insert(root, 2);
	insert(root, 4);
	TreeNode* found = search(root, 4);
	if (found) {
		cout << "Found: " << found->val << endl;
	} else {
		cout << "Not found" << endl;
	}

	cout << "前序遍历：";
	preorder(root);
	cout << endl;
	cout << "中序遍历：";
	inorder(root);
	cout << endl;
	cout << "后序遍历：";
	postorder(root);
	cout << endl;
	cout << "层次遍历：";
	levelOrder(root);
	cout << endl;

	return 0;
}
#endif

//1、Invert Binary Tree
//反转二叉树
//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//示例 1：
//Input: root = [1, 2, 3, 4, 5, 6, 7]
//Output : [1, 3, 2, 7, 6, 5, 4]

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		if (root) {
			swap(root->left, root->right);
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};

class Solution1 {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root) return nullptr;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front();
			q.pop();
			swap(node->left, node->right);
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		return root;
	}
};


int main() {
	TreeNode* root = nullptr;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 7);
	insert(root, 2);
	insert(root, 4);
	cout << "前序遍历：";
	preorder(root);
	cout << endl;

	Solution sol;
	sol.invertTree(root);
	cout << "前序遍历：";
	preorder(root);
	cout << endl;

	Solution1 sol1;
	sol1.invertTree(root);
	cout << "前序遍历：";
	preorder(root);
	cout << endl;
	return 0;
}

#endif
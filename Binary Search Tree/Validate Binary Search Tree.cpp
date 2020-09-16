/*
Link : https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool isvalid(TreeNode* node, int upper, int lower, bool upperflag, bool lowerflag)
	{
		if (node == NULL) return true;
		if (lowerflag and node->val <= lower) return false;
		if (upperflag and node->val >= upper) return false;
		bool res = true;
		res &= isvalid(node->left, min(upper, node->val), lower, true, lowerflag);
		res &= isvalid(node->right, upper, max(lower, node->val), upperflag, true);

		return res;


	}
	bool isValidBST(TreeNode* root) {

		return isvalid(root, INT_MAX, INT_MIN, false, false);
	}
};
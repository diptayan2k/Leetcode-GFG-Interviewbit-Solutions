/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
  
 Link : https://leetcode.com/problems/symmetric-tree/
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
    
    bool ismirror(TreeNode* nodea, TreeNode* nodeb)
    {
        if(nodea==NULL and nodeb==NULL) return true;
        if(nodea==NULL or nodeb==NULL) return false;
        if(nodea->val!=nodeb->val) return false;
        
        bool res = true;
        
        res&= ismirror(nodea->right, nodeb->left);
        res&= ismirror(nodea->left, nodeb->right);
        
        return res;
        
    }
    bool isSymmetric(TreeNode* root) {
        
        return ismirror(root,root);        
    }
};

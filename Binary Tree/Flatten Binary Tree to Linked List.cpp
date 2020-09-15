/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/*


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
    void flatten(TreeNode* root) {
        
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) return;
        
        // if left subtree exists, first flatten the left subtree
        if(root->left!=NULL) flatten(root->left);
        
        TreeNode* tempright = root->right;
        
        // insert the flattened left subtree in right
        root->right = root->left;
        root->left = NULL;
        
        TreeNode* temp = root;
        
        // insert the original right subtree at the end
        while(temp->right!= NULL) temp=temp->right;
        
        temp->right = tempright;
        
        // flatten the right subtree
        flatten(root->right);
        
    }
};

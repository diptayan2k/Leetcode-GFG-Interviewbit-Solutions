/*
Link : https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
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
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> s;
        
        do{
            if(root==NULL and !s.empty())
            {
                root = s.top();
                k--;
                if(k==0) break;
                s.pop();
                root = root->right;
            }
            if(root!=NULL)
            {
                s.push(root);
                root = root->left;
            }
            
        }while(!s.empty());
        
        return root->val;
        
    }
};

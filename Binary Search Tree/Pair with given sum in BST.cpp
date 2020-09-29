/*
Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        
        stack<TreeNode *> st;
        do
        {
            if(root==NULL and !st.empty())
            {
                root = st.top();
                st.pop();
                inorder.push_back(root->val);
                root=root->right;
                
            }
            if(root!=NULL)
            {
                st.push(root);
                root = root->left;
            }
        }while(!st.empty());
        
        int i = 0, j = inorder.size()-1;
        
        while(i<j and i<inorder.size() and j>=0)
        {
            if(inorder[i]+inorder[j]==k) return true;
            else if(inorder[i]+inorder[j]<k) i++;
            else j--;
        }
        
        return false;
        
    }
};

/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
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
    

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        stack<TreeNode*> st;
        
        TreeNode* current = root;
        
        
        do
        {
            if(current==NULL and !st.empty())
            {
                current = st.top();
                st.pop();
                ans.push_back(current->val);
                current = current->right;
            }
            if(current!=NULL)
            {
                st.push(current);
                current = current->left;
            }
        }while(!st.empty());
        
    return ans;
        
    }
};

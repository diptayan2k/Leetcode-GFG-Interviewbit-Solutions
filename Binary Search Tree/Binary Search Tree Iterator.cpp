/*
Link : https://leetcode.com/problems/binary-search-tree-iterator/
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.

Note:
next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
You may assume that next() call will always be valid, that is, there will be at least a next smallest number in the BST when next() is called.
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
class BSTIterator {
public:
    
    stack<TreeNode*> st;
   
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    // push left nodes repeateadly
    void inorder(TreeNode* node)
    {
        while(node!=NULL)
        {
            st.push(node);
            node = node->left;
        }
        
    }
    
    /** @return the next smallest number */
    int next() {
        
        int val; 
        TreeNode* current = st.top();
        val = current->val;
        st.pop();
        
        if(current->right!=NULL)
        {
            current= current->right;
            inorder(current);
        }
        
        
        return val;        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty()) return false;
        return true;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

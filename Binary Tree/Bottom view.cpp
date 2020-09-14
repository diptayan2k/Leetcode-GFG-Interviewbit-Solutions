// Link : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

void traverse(Node* node,int height,int horizontal_dist, 
              map<int, pair<int,int> >& mp)
{
    
    if(node==NULL) return;
    
    if(mp.find(horizontal_dist)==mp.end()) mp[horizontal_dist] = {node->data,height};
    else if(mp[horizontal_dist].second<=height) mp[horizontal_dist] = {node->data,height};
   
    traverse(node->left,height+1,horizontal_dist-1,mp);
    traverse(node->right,height+1,horizontal_dist+1,mp);
}
// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
    map<int,pair<int,int> > mp;
    
    traverse(root,0,0,mp);
    vector<int> ans;
    for(auto i:mp) ans.push_back(i.second.first);
    
    return ans;
   
}

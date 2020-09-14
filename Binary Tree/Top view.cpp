\\ Link : https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

void traverse(Node *root,int hori_dist,int height, map<int,pair<int,int> >& mp)
{
    if(root==NULL) return;
    
    if(mp.find(hori_dist)==mp.end()) mp[hori_dist] = {root->data, height};
    else if(mp[hori_dist].second>height) mp[hori_dist] = {root->data,height};
    
    traverse(root->left,hori_dist-1,height+1,mp);
    traverse(root->right,hori_dist+1,height+1,mp);
}
// function should print the topView of the binary tree
void topView(struct Node *root)
{
    map<int,pair<int,int> > mp;
    traverse(root,0,0,mp);
    vector<int> ans;
    
    for(auto i:mp)
    {
        cout<<i.second.first<<" ";
    }
    
}

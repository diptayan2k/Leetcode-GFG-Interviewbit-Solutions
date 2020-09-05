/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

Link : https://www.interviewbit.com/problems/subset/
*/

void all_subsets(int idx, vector<int>&A, vector<int>& current, vector<vector<int> >& ans)
{
    if(idx==A.size())
    {
        return;
    }
    
    current.push_back(A[idx]);
    ans.push_back(current);
    all_subsets(idx+1,A,current,ans);
    current.pop_back();
    
    
    all_subsets(idx+1,A,current,ans);
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    vector<int> current;
    vector<vector<int> > ans;
    
    sort(A.begin(),A.end());
    ans.push_back({});
    
    all_subsets(0,A,current,ans);
    
    return ans;
    
}

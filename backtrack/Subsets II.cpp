/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

Link : https://www.interviewbit.com/problems/subsets-ii/
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
    
    int nextidx = idx+1;
    while(nextidx<A.size() and A[nextidx]==A[idx]) nextidx++;
    
    all_subsets(nextidx,A,current,ans);
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    vector<int> current;
    vector<vector<int> > ans;
    
    sort(A.begin(),A.end());
    ans.push_back({});
    
    all_subsets(0,A,current,ans);
    
    return ans;
    
}

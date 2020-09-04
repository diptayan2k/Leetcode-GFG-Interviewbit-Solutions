/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/

class Solution {
public:
    
    void allcombinations(int idx, int sum,int target, vector<int>& candidates,
                     vector<int>& combinations, vector<vector<int> >& ans)
    {
        
        if(sum>target) return;
        
        if(idx==candidates.size())
        {
            if(sum==target)
            {
                ans.push_back(combinations);
            }
            return;
        }
        
        combinations.push_back(candidates[idx]);
        allcombinations(idx+1,sum+candidates[idx],target,candidates,combinations,ans);
        combinations.pop_back();
        
        int nextidx = idx+1;
        while(nextidx<candidates.size() and candidates[nextidx]==candidates[idx]) nextidx++;
        // A number can't occur more than once in same recursion depth this will lead to 
        // duplicate combinations
        
        allcombinations(nextidx++,sum,target,candidates,combinations,ans);
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> combination;
        vector<vector<int> > ans;
        sort(candidates.begin(),candidates.end());
        allcombinations(0,0,target,candidates,combination,ans);
        
        return ans;
        
    }
};

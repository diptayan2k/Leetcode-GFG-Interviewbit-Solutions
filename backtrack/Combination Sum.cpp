/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in
candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Link : https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    
    void combinationSumProblem(int sum, int target,vector<int>& candidates,
                              vector<int>& combination, vector<vector<int> >& ans)
    {
        if(sum==target)
        {
            ans.push_back(combination);
            return;
        }
        
        if(sum>target) return;
                
        
        for(auto i:candidates)
        {
            if(!combination.empty() and combination.back()>i) break;
            combination.push_back(i);
            combinationSumProblem(sum+i,target,candidates,combination,ans);
            combination.pop_back();
        }
       
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        
        sort(candidates.begin(),candidates.end(),greater<int>());
        vector<int> combination;
        vector<vector<int> > ans;
        combinationSumProblem(0,target,candidates,combination,ans);
        
        return ans;
        
    }
};


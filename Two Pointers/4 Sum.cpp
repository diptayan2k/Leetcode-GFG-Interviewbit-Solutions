/*
Link : https://leetcode.com/problems/4sum/
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int> > ans;
        int n = nums.size();
        if(n<4) return ans;
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++)
        {
            if(i>0 and nums[i]== nums[i-1]) continue;
            for(int j = i+1;j<n; j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                
                int left = j+1;
                int right = n-1;
                
                while(left<right and left<n and right>j)
                {
                    
                    if(nums[i]+nums[j]+nums[left]+nums[right]<target)
                    {
                        int x = nums[left];
                        while(left<n and nums[left]==x) left++;
                    }
                    else if(nums[i]+nums[j]+nums[left]+nums[right]>target)
                    {
                        int x = nums[right];
                        while(right>j and nums[right]==x) right--;
                    }
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int x = nums[left];
                        while(left<n and nums[left]==x) left++;
                        x = nums[right];
                        while(right>j and nums[right]==x) right--;
                         
                    }
                    
                }
                
            }
        }
     
        return ans;
    }
};

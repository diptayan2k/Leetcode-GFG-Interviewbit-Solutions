/*
Link : https://leetcode.com/problems/3sum/
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int target = 0;
        vector<vector<int> > ans;
        for(int i = 0; i<n; i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            
            int left = i+1;
            int right = n-1;
            
            while(left<right and left<n and right>i)
            {
                    
                if(nums[i]+nums[left]+nums[right]<target)
                {
                    int x = nums[left];
                    while(left<n and nums[left]==x) left++;
                }
                else if(nums[i]+nums[left]+nums[right]>target)
                {
                    int x = nums[right];
                    while(right>i and nums[right]==x) right--;
                }
                else
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    int x = nums[left];
                    while(left<n and nums[left]==x) left++;
                    x = nums[right];
                    while(right>i and nums[right]==x) right--;
                }
                    
            }
            
        }
        
        return ans;
    }
};

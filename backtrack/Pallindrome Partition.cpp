/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]

Link : https://leetcode.com/problems/palindrome-partitioning/

*/

class Solution {
public:
    
    void pallindromePartition(int idx, int prev,string &s, vector<string>& partitions,
                              vector<vector<string> >& ans)
    {
        if(idx==s.size())
        {
            string current = s.substr(prev,s.size()-prev);
            int len = s.size()-prev;
            for(int i = 0; i<len/2; i++)
            {
                if(current[i]!=current[len-i-1]) return;
            }
            partitions.push_back(current);
            ans.push_back(partitions);
            partitions.pop_back();
            return;
        }
        
        string current = s.substr(prev,idx-prev);
        int len = idx-prev;
        bool is_pallindrome = true;
        for(int i = 0; i<len/2;i++) 
            if(current[i]!=current[len-i-1])
            {
                is_pallindrome = false;
                break;
            }
        
        if(len>0 and is_pallindrome)
        {
            partitions.push_back(current);
            pallindromePartition(idx+1,idx,s,partitions,ans);
            partitions.pop_back();
        }
        
        pallindromePartition(idx+1,prev,s,partitions,ans);
        
    }
    vector<vector<string>> partition(string s) {
    
        vector<string> partitions;
        vector<vector<string> > ans;
        
        pallindromePartition(0,0,s,partitions,ans);
        
        return ans;
        
    }
};

/*
he set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"

Link : https://leetcode.com/problems/permutation-sequence/
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        
        int fact[n+1];
        fact[0] = 1;
        
        vector<int> numbers;
        
        for(int i =1; i<=n; i++) 
        {
            fact[i] = fact[i-1]*i;
            numbers.push_back(i);
        }
        string s = "";
        
        for(int i = n; i>1; i--)
        {
            int p = (k/fact[i-1])+((k%fact[i-1])!=0);
            s+=(char)('0'+numbers[p-1]);
            numbers.erase(numbers.begin()+p-1);
            k%=fact[i-1];
            if(k==0) k=fact[i-1];
        }
        s+=(char)('0'+numbers[0]);
        
        
        return s;
        
    }
};

/*
Link : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 
'B' occurs twice in array. Find these two numbers.
*/

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        
        int *ans = new int(2);
        
        if(n==2)
        {
            if(arr[0]==1) 
            {
                ans[0] = 1;
                ans[1] = 2;
            }
            else
            {
                ans[0] = 2;
                ans[1] = 1;
            }
            return ans;
        }
        int x = 0;
        for(int i = 0; i<n; i++) x^=(arr[i]^(i+1));
        
        
        int rightmost = -1;
        for(int i = 0; i<=18;i++)
        {
            if(((1<<i)&x)!=0)
            {
                rightmost = (1<<i);
                break;
            }
        }
        
        int setbucket=0, notsetbucket=0;
        
        
        for(int i = 0; i<n; i++)
        {
            if((rightmost&arr[i])!=0) setbucket^=arr[i];
            else notsetbucket^=arr[i];
        }
        
        for(int i = 1;i<=n;i++)
        {
            if((rightmost&i)!=0) setbucket^=i;
            else notsetbucket^=i;
        }
        
        
        ans[0] = setbucket;
        ans[1] = notsetbucket;
        
        
        for(int i = 0; i<n; i++)
        {
            if(arr[i]==notsetbucket) 
            {
                swap(ans[0],ans[1]);
                break;
            }
        }
        
        return ans;

    }
};

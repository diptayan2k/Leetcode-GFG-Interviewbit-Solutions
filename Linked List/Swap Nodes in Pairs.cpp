/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes. Only nodes itself may be changed.

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Link : https://leetcode.com/problems/swap-nodes-in-pairs/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL) return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = NULL;
        ListNode* temp;
    
        
        while(first!=NULL and second!=NULL)
        {
            temp = second->next;
            second->next = first;
            first->next = temp;
            
            if(prev!=NULL)
            {
                prev->next = second;
            }
            else head = second;

            prev = first;
            first = temp;
            if(first==NULL) break;
            second = temp->next;
            
        }
        
        return head;
    }
};

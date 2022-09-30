82. Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]
 
Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
  
  
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode dummyHead(0, head);
        dummyHead.next = head;
        ListNode *iter = dummyHead.next;
        ListNode *parrentIter = &dummyHead;
        
        bool bSkip = false;
        while(iter && iter->next){
            if(iter->val != iter->next->val){
                if(bSkip) {
                    parrentIter->next = iter->next;
                    bSkip = false;
                }
                else parrentIter = iter;
            }else bSkip = true; //this val equals next val, both need to be removed later
            
            iter = iter->next;
        }
        
        if(bSkip) parrentIter->next = iter->next;
            
        return dummyHead.next;
    }
};

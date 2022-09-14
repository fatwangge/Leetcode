61. Rotate List
Given the head of a linked list, rotate the list to the right by k places.

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
  
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || 0==k || !(head->next)) return head;
        
        //first process k, if k is too large, mod it; if k is multiple of length, means no rotation
        int length = 0;
        ListNode *it = head;
        while(it){
            it = it->next;
            length++;
        }
        k = k%length;
        if(0 == k) return head;
        
        ListNode *p1 = head, *p2 = head;
        for(int i = 0; i < k; i++)  p1 = p1->next;
        while(p1->next){ p1 = p1->next; p2 = p2->next;}
        //now p1 is last node and p2->next points to the head of the new list
        ListNode* newHead = p2->next;
        p2->next = NULL;
        p1->next = head;
        
        return newHead;
    }
};

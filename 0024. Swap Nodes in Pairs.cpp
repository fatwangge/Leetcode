24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
  
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
        if(!head) return NULL;
        if(head->next == NULL) return head;
        ListNode *pHead = head;
        ListNode *pNext = head->next;
        
        //Swap the first and second element
        pHead->next = pNext->next;
        pNext->next = pHead;
        pHead = pNext;
        pNext = pHead->next;
        
        while(pNext->next && pNext->next->next){
            Swap(pNext);//swap the two elements after pNext
            pNext = pNext->next->next;
        }
        
        return pHead;
    }
    
    //Given the head, there are 3 steps for the swap
    void Swap(ListNode* head){
        ListNode *p = head->next; //assign the second pointer
        
        head->next = p->next;    //step 1: link the first pointer: 2->4
        p->next = p->next->next; //step 2: link the second pointer: 3->5
        head->next->next = p;    //step 3: 4->3
    }
};

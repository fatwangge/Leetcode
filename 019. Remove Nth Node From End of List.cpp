19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?

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
    //Extra challenge: do this in one pass
    
    //Method 1: recursive
    //Algorithm is to find the previous elem before nth element, and remove the nth element
    //Difficult part is when the nth element is the head
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;
        bool bRemove = false;
        recursive(head, counter, n, bRemove);
        return bRemove ? head : head->next;
    }
    
    void recursive(ListNode *head, int &counter, int n, bool &bRemove){
        if(!head) return;
        
        recursive(head->next, counter, n, bRemove);
        counter++;
        if(counter == n+1){
            head->next = head->next->next;
            bRemove = true;
        }
    }
    
    //Method 2: two pointers
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head) return NULL;
        ListNode* iter = head;
        ListNode* deleteIter = head;
        
        //Step 1: create the n gap between two pointers
        for(int i = 0; i < n; i++) iter = iter->next;
        if(!iter) return head->next;//Special case: Return if the element to be removed is head

        //Step 2: keep going until the end
        while(iter->next != NULL){
            iter = iter->next;
            deleteIter = deleteIter->next;
        }
        
        ListNode* tmpNode = deleteIter->next;
        deleteIter->next = tmpNode->next;
        delete tmpNode;
        
        return head;  
    }
 
};

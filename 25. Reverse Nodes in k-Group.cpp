25. Reverse Nodes in k-Group (HARD)
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

Follow-up: Can you solve the problem in O(1) extra memory space?
  
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
    //Method 1: use recursive. Easy to make mistake, need to draw an image.
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(0, head);//need delete later
        ListNode *iter = dummyHead;
        ListNode *processPointer = dummyHead;
        
        int counter = 0;
        while(true){
            counter++;
            iter = iter->next;
            if(!iter) break;
            
            if(counter == k){
                ListNode *tmp = processPointer->next;
                recursiveReverse(processPointer, 1, k);
                processPointer = tmp;
                iter = tmp;
                counter = 0;
            }
        }
        
        return dummyHead->next;
    }
    
    //reverse the nodes after head, new head is returned
    ListNode *recursiveReverse(ListNode *head, int n, int k){
        if(!head) return NULL;
        if(head->next == NULL) return NULL;
        if(head->next->next == NULL) return head->next;
        if(n == k) return head->next;
        
        ListNode *last = head->next;//this need to put after the tail
        ListNode *tail = head->next->next;
        
        head->next = recursiveReverse(head->next, n+1, k);
        
        //insert last in the end
        last->next = tail->next;
        tail->next = last;
        
        return head->next;
    }

    //Method 2: non-recursive method
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || head->next == NULL || k == 1) return head;
        
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode *iter1 = head;
        ListNode *iter0 = dummyHead;
        int count = 0;
        
        while(iter1 != NULL){
            count++;
            if(count == k){
                iter0 = Reverse(iter0, iter1->next);
                iter1 = iter0->next;
                count = 0;
            }
            else iter1 = iter1->next;
        }
        
        return dummyHead->next;
    }
    
    //Since only constant memory is allowed, time cost is O(k)
    ListNode* Reverse(ListNode *begin, ListNode *end){
        ListNode* pre = begin->next;
        ListNode* current = pre->next;
        
        while(current != end){
            pre->next = current->next;
            current->next = begin->next;
            begin->next = current;
            current = pre->next;
        }
        return pre;
    }

};

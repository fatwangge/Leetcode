2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 
Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
  
  
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *iter1 = l1, *iter2 = l2;   
        ListNode *returnHead = NULL, *iter = NULL; //remember to intialize pointer to NULL
        
        bool carry = false;
        while(true){
            ListNode *newNode = new ListNode(Add(iter1?iter1->val:0, iter2?iter2->val:0, carry));
            if(!returnHead) returnHead = newNode; //use ! to initialize header node
            if(!iter) iter = newNode;
            else {
                iter->next = newNode;
                iter = iter->next;
            }
            
            if(iter1)iter1 = iter1->next;
            if(iter2)iter2 = iter2->next;
            if(!iter1&&!iter2)break;
        }
        
        if(carry) iter->next = new ListNode(1);
        
        
        return returnHead;
    }
    
    int Add(int val1, int val2, bool &carry){ //write a function to add sum
        int returnVal = val1+val2+(carry?1:0);
        if(returnVal >= 10){
            returnVal -= 10;
            carry = true;
        }else carry = false;
        return returnVal;
    }
};

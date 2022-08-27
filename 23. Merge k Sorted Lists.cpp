23. Merge k Sorted Lists (HARD)
  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
  

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
    //Method1: Easy brute force method: nlogn
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vect;
        ListNode *res = NULL;
        for(int i = 0; i < lists.size(); i++){
            ListNode *p = lists[i];
            while(p){
                vect.push_back(p->val);
                p = p->next;
            }
        }
        sort(vect.begin(), vect.end());
        if(vect.size() == 0) return NULL;
        res = new ListNode(vect[0], NULL);
        if(vect.size() == 1) return res;
        
        ListNode *q = res;
        for(int i = 1; i < vect.size(); i++){
            q->next = new ListNode(vect[i], NULL);
            q = q->next;
        }
        return res;
    }
    //Method2: Merge 2 sorted list, reduce k lists to k/2 lists...Then repeat, nlogk
};
  

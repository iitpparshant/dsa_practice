// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

//                                 2181. Merge Nodes in Between Zeros


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
    ListNode* mergeNodes(ListNode* head) {
        int sum=0;
        ListNode*dummy= new ListNode(-1);
        ListNode* ans= dummy;
        while(head){
            sum+= head->val;
            if(head->val==0){
                if(sum>0){
                    ListNode*t=new ListNode(sum);
                    ans->next= t;
                    ans= ans->next;
                }
                sum=0;
            }
            head= head->next;
        }
        return dummy->next;
    }
};
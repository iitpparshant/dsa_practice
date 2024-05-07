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
    ListNode* reverse(ListNode* head){
        ListNode*curr=head;
        ListNode*next=NULL;
        ListNode*prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode*second=reverse(head);
        int carry=0;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(second!=NULL|| carry){
            int sum=0;
            if(second){
                sum+=(2*second->val);
                second= second->next;
            }
            sum+=carry;
            carry= sum/10;
            ListNode* curr = new ListNode(sum % 10);
            temp->next= curr;
            temp= temp->next;
        }
        return reverse(dummy->next);
    }
};
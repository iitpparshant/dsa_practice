// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        ListNode* ans= new ListNode(-1);
        ListNode* temp= ans;
        ans->next= head;
        while(head){
            if(mp.find(head->val)==mp.end()){
               temp->next= head;
                temp= temp->next;
            }
                head= head->next;
        }
        temp->next= NULL;
        return ans->next;
    }
};
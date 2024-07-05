//     https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/\

//                             2058. Find the Minimum and Maximum Number of Nodes Between Critical Points


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int x= head->val;
        head= head->next;
        vector<int>ans;
        int i=1;
        while(head->next){
            if(head->val>x && head->val>head->next->val){
                ans.push_back(i);
            }
            else if(head->val<x && head->val<head->next->val){
                ans.push_back(i);
            }
            x= head->val;
            head= head->next;
            i++;
        }
        int y=INT_MAX;
        int n= ans.size();
        for(int j=1;j<n;j++){
            y= min(y,ans[j]-ans[j-1]);
        }
        if(y==INT_MAX){
            return {-1,-1};
        }
        return {y,ans[n-1]-ans[0]};
    }
};
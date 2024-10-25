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

private:
    int lgt(ListNode* head){
        int ct=0;
        ListNode* temp = head;
        while(temp){
            ct++;
            temp=temp->next;
        }
        return ct;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int len = lgt(head);
        int middle=len/2; //0 based indexing me aisa hi hota he, even-odd both are calculated right, don't repeat mistake again

        ListNode* temp = head;

        for(int i=0;i<middle;i++){
            temp=temp->next;
        }
        return temp;
        
    }
};
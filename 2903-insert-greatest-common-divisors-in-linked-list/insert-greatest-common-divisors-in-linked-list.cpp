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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp = insertGreatestCommonDivisors(head->next);
        
        ListNode* gcdNode = new ListNode(__gcd(head->val,head->next->val));

        gcdNode->next = temp;
        head->next = gcdNode;   
        
        return head;
    }
};
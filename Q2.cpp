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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflow = 0;
        ListNode* result = new ListNode();
        ListNode* head = result;
        bool carry = false;
        while(l1->next && l2->next){
            int sum = l1->val + l2->val;
            if(carry){
                sum += 1;
                carry = false;
            }
            int ones = 0;
            if ( sum >= 10){
                carry = true;
                ones = sum - 10;
            }
            else{
                ones = sum;
            }
            
            result->val = ones;
            
            ListNode* nextresultdig = new ListNode();
            result->next = nextresultdig;             
            result = nextresultdig;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        //when we're done here, either l1 or l2 has no next
        int sum = l1->val + l2->val;
        if(carry){
            sum += 1;
            carry = false;
        }
        int ones = 0;
        if ( sum >= 10){
            carry = true;
            ones = sum - 10;
        }
        else{
            ones = sum;
        }
        result->val = ones;
        
        //now handle any remaining list of either l1 or l2.
        while(l1->next || l2->next){
            result->next = new ListNode();
            result = result->next;
            
            if(l1->next){
                l1 = l1->next;
                result->val = l1->val;
                if(carry){
                    result->val += 1;
                    carry = false;
                }
                
            }
            if(l2->next){
                l2 = l2->next;
                result->val = l2->val;
                if(carry){
                    result->val += 1;
                    carry = false;
                }
            }
            if(result->val >= 10){
                carry = true;
                result->val -= 10;
            }
        }
        
        if(carry){
            result->next = new ListNode();
            result->next->val = 1;
        }
        return head;
    }
};
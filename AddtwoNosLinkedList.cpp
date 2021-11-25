 #include <bits/stdc++.h>
 using namespace std;
 
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;  
        
        int sum = 0;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL){
            
            int x = (l1 != NULL)? l1->val : 0;
            int y = (l2 != NULL)? l2->val : 0; 
            
            sum = x + y + carry;
            carry = floor(sum / 10);
            
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
            
            if(l1!= NULL) l1 = l1->next;
            if(l2!= NULL) l2 = l2->next;
            
        }
                
            if(carry > 0)
                l3->next = new ListNode(carry);
            
    
            return head->next;
    }
};

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode   * returner = (ListNode * )malloc(sizeof(ListNode));
        ListNode * start = returner;
        
        if(l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        while(l1 !=  NULL && l2 != 0)
        {
            if(l1->val > l2-> val)
            {
                returner->val = l2->val;
                l2 = l2->next;
                
                returner->next = (ListNode * )malloc(sizeof(ListNode));
                returner = returner->next;
                //returner->next = NULL;
            }
            else
            {
                returner->val = l1->val;
                l1 = l1->next;
                
                returner->next = (ListNode * )malloc(sizeof(ListNode));
                returner = returner->next;
                //returner->next = NULL;
            }
        }
        ListNode   * previous;
    
        if(l2 == NULL)
        {
            //cout<<"Eter";
            while(l1 !=  NULL)
            {
                returner->val = l1->val;
                l1 = l1->next;
                previous = returner;
                if(l1 != NULL)
                {
                    returner->next = (ListNode * )malloc(sizeof(ListNode));
                    returner = returner->next;
                }
                returner->next = NULL;
            }
        }
        else if(l1 == NULL)
        {
            //cout<<"Eter";
            while(l2 != NULL)
            {
                returner->val = l2->val;
                l2 = l2->next;
                previous = returner;
                if(l2 != NULL)
                {
                    returner->next = (ListNode * )malloc(sizeof(ListNode));
                    returner = returner->next;
                }
                returner->next = NULL;
            }
        }
        
        
        //free(returner);
        //previous->next == NULL;
        
        //returner->next = NULL;
        
        return start;
        
    }
};

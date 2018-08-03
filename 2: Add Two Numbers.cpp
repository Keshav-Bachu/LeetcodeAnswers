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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *lfin = (ListNode *) malloc(sizeof(ListNode));
        ListNode* prev;
        ListNode *ret = lfin;
        
        int carryover = 0;
        ListNode *l3 = l1;
        ListNode *l4 = l2;
        int sum;
        
        while(l3 != NULL && l4 != NULL)
        {
            sum = l3->val + l4->val;
            //cout << sum << '\n';
            if(carryover ==  1)
            {
                sum++;
                carryover = 0;
            }
            
            if(sum > 9)
            {
                sum -= 10;
                carryover = 1;
                
            }
            lfin->val = sum;
            l3 = l3->next;
            l4 = l4->next;
            
            if(l3 != NULL ||l4 != NULL)
            {
                lfin->next = (ListNode *) malloc(sizeof(ListNode));
                lfin = lfin->next;
            }
            
            else
            {
                lfin->next = NULL;
            }
        }
        
        if(l3  == NULL)
        {
            while(l4 != NULL)
            {
                sum = l4->val;
                //cout << sum << '\n';
                if(carryover ==  1)
                {
                    sum++;
                    carryover = 0;
                }

                if(sum > 9)
                {
                    sum -= 10;
                    carryover = 1;

                }
                lfin->val = sum;
                l4 = l4->next;

                if(l4 != NULL)
                {
                    lfin->next = (ListNode *) malloc(sizeof(ListNode));
                    lfin = lfin->next;
                }

                else
                {
                    lfin->next = NULL;
                }
            }
        }
        else if(l4 == NULL)
        {
            while(l3 != NULL)
            {
                sum = l3->val;
                //cout << sum << '\n';
                if(carryover ==  1)
                {
                    sum++;
                    carryover = 0;
                }

                if(sum > 9)
                {
                    sum -= 10;
                    carryover = 1;

                }
                lfin->val = sum;
                l3 = l3->next;

                if(l3 != NULL)
                {
                    lfin->next = (ListNode *) malloc(sizeof(ListNode));
                    lfin = lfin->next;
                }

                else
                {
                    lfin->next = NULL;
                }
            }
        }
        
        if(carryover == 1)
        {
            lfin->next = (ListNode *) malloc(sizeof(ListNode));
            lfin = lfin->next;
            lfin->val = 1;
            lfin->next = NULL;
        }
        
        
        return ret;
        
        
    }
};

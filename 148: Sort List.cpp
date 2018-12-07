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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        return mergeSortLinkedList(head);
    }
    
    
    ListNode * mergeSortLinkedList(ListNode * head)
    {
        //split and call the function again
        int i = 0;
        ListNode * temp = head;
        while(temp != NULL)
        {
            i++;
            //cout << temp->val << ' ';
            temp = temp->next;
        }
        //cout <<endl <<  '\t' << i;
        //cout << endl;
        
        //check for 1 and 2, at which case dont continue the rest
        if(i == 2)
        {
            ListNode * num1 = head;
            ListNode * num2 = head->next;
            if(num1->val > num2->val)
            {
                num2->next = num1;
                num1->next = NULL;
                return num2;
            }
            
            return head;
        }
        if(i == 1)
        {
            return head;
        }
        
        int cut = i/2;
        temp = head;
        
        for(int j = 1; j < cut; j++)
        {
            temp = temp->next;
        }
        //cout <<'\t' <<  temp->val << endl;
        
        ListNode * set1 = mergeSortLinkedList(temp->next);
        temp->next = NULL;
        ListNode * set2 = mergeSortLinkedList(head);
        
        //merge the stuff back
        ListNode * mergeTotal = NULL;
        ListNode * returner;
        if(set1->val > set2->val)
        {
            mergeTotal = set2;
            set2 = set2->next;
        }
        else
        {
            mergeTotal = set1;
            set1 = set1->next;
        }
        returner = mergeTotal;
        
        while(set1 != NULL && set2 != NULL)
        {
            if(set1->val > set2->val)
            {
                mergeTotal->next = set2;
                set2 = set2->next;
            }
            else
            {
                mergeTotal->next = set1;
                set1 = set1->next;
            }
            mergeTotal = mergeTotal->next;
        }
        
        //fill the rest of the values
        while(set1 != NULL)
        {
            mergeTotal->next = set1;
            mergeTotal = mergeTotal->next;
            set1 = set1->next;
        }
        while(set2 != NULL)
        {
            mergeTotal->next = set2;
            mergeTotal = mergeTotal->next;
            set2 = set2->next;
        }
        
        return returner;
    }
};

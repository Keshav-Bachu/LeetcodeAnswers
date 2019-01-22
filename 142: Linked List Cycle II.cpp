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
    ListNode *detectCycle(ListNode *head) {
        
        map <long, long> addressVals;
        ListNode * temp = head;
        while(temp != NULL)
        {
            //cout << temp->val << endl;
            if(addressVals.find((long)temp) == addressVals.end())
            {
                addressVals[(long)temp] = (long)temp->next;
            }
            else
            {
                return temp;
            }
            temp = temp->next;
        }
        
        return NULL;
    }
};

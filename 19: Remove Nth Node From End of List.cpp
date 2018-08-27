/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include vector
#include iostream
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> storage;
        ListNode * temp = head;
        
        while(head != NULL)
        {
            storage.push_back(head);
            head = head->next;
        }
        int pos = storage.size() - n - 1;
        if(pos < 0)
        {
            temp = temp->next;
            return temp;
        }
        
        head = storage[pos];
        #cout << head->val << "\n";
        if(n != 1 && storage.size() != 1)
        {
            head->next = head->next->next;
        }
        else if(storage.size() == 1)
        {
            temp = NULL;
        }
        else{
            head->next = NULL;
        }
        
        return temp;
        
    }
};

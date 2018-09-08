/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //have access to a bunch of linked lists
        ListNode * tracker = NULL;
        ListNode * start = NULL;
        
        bool firstInstance = true;
        while(1)
        {
            //find the lowest element
            //cout << lists.size() << endl;
            int low = 99999999999;
            int index = -1;
            for(int i = 0; i < lists.size(); i++)
            {
                if(lists[i] != NULL && lists[i]->val < low)
                {
                    low = lists[i]->val;
                    index = i;
                }
            }
            //cout << index << endl;
            if(index == -1)
            {
                if(tracker == NULL)
                {
                    return tracker;
                }
                tracker->next = NULL;
                return start;
            }
            
            
            if(firstInstance == true)
            {
                
                firstInstance = false;
                tracker = lists[index];
                start = lists[index];
            }
            else
            {
                tracker->next = lists[index];
                tracker = tracker->next;
            }
            lists[index] = lists[index]->next;
            
            //cout << low << endl;
            //cout << start->val << endl;
        }
    }
};

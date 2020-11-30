#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
    unordered_set <ListNode*> in_cycle;
public:

    ListNode *detectCycle_without_hashset(ListNode *head) {
        if(!head)
            return head;
        
        ListNode* slow_ptr = head, *fast_ptr = head;
        bool node_found = false;
        
        while(fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if(slow_ptr == fast_ptr) {
                node_found = true;
                break;
            }
        }
        
        if(!node_found)
            return NULL;
        
        slow_ptr = head;
        
        while (slow_ptr != fast_ptr) {
            cout << slow_ptr->val << " " << fast_ptr->val << endl;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
            }
        return slow_ptr;
    }

    ListNode *detectCycle_with_hashset(ListNode *head) {
        if(!head)
            return head;
        
        ListNode* slow_ptr = head, *fast_ptr = head->next;
        
        while(fast_ptr) {
            if(slow_ptr == fast_ptr) {
                break;
            }
            if(!fast_ptr->next)
                return NULL;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        
        if (!fast_ptr)
            return NULL;
        
        while (!in_cycle.count(slow_ptr)) {
            in_cycle.insert(slow_ptr);
            slow_ptr = slow_ptr->next;
        }
        
        ListNode* l = head;
        while (l) {
            if(in_cycle.count(l))
                return l;
            l = l-> next;
        }
        
        return NULL; 
    }
};
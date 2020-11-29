#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
        ListNode *rem = new ListNode(0);
        rem->next = head;
        ListNode *first, *second;
        first = rem;
        second = rem;
        for (int  i = 0; i <= n ; i ++) {
            first = first -> next;
        }
        while (first != NULL) {
            cout << second -> val << " " << first -> val << endl;
            second = second->next;
            first = first-> next;
        }
        second -> next = second -> next -> next;
        return rem->next;
    }
};
#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        if (l1 -> val > l2 -> val)
            swap(l1, l2);
        
        ListNode* l = l1, *temp; 
        int value;
        
        while ( l2 != NULL) {
            value = l2 -> val;
            cout << value << " ";
            while (l1 -> next && l1 -> next -> val < value) 
                l1 = l1 -> next;
            temp = l1 -> next;
            l1 -> next = l2;
            l2 = l2 -> next;
            l1 -> next -> next = temp;
        }
        return l;
    }
};
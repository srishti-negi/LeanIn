#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB)
            return headA;
        while(headA) {
            ListNode*l = headB;
            while(l) {
                if (headA == l)
                    return headA;
                l = l->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
};
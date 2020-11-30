#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://leetcode.com/problems/design-linked-list/

class MyLinkedList {
    struct node {
        int data;
        node* next;
    };
    node* head;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        node* l;
        l = head;
        while (index >= 0 && l) {
            if (index == 0)
                return l->data;
            index--;
            l = l->next; 
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node* l = new node();
        l -> data = val;
        l -> next = head;
        head = l;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *l, *new_node = new node();
        new_node -> data = val;
        new_node -> next = NULL;
        l = head;
        while (l && l->next)
            l = l -> next;
        if (l)
            l->next = new_node;
        else
            head = new_node;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        node* l, * new_node = new node();
        new_node -> data = val;
        l = head;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        while (index >= 0 && l) {
            if (index == 1) {
                new_node -> next = l-> next;
                l -> next = new_node;
            }    
            l = l-> next;
            index--;
        }
        if (l && index == 0){
            new_node -> next = l-> next;
            l -> next = new_node;
        }    
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        node* l;
        l = head;
        if (index == 0 && head) {
            head = head->next;
        }
        while (index >= 1 && l) {
            if (index == 1 ) {
                if(l->next)
                    l -> next = l->next->next;
                else
                    l->next = nullptr;
                break;
            }
            index--;  
            l = l-> next;
        }   
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
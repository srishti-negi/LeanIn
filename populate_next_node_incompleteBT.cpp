#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    Node* next_node (Node* root) {
        if (!root)
            return nullptr;
        if (root->left) 
            return root -> left;
        if (root -> right)
            return root -> right;
        return next_node(root -> next);
    }
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        if(root->left) {
            if (root->right)
                root->left->next = root->right;
            else
                root ->left->next = next_node(root->next);
        }
        if (root->right)
            root->right->next = next_node(root->next);
        
        connect (root -> right);
        connect (root -> left);
        return root;
    }
};
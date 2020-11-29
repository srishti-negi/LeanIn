#include <iostream>
#include<vector>
using namespace std;

//https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    string traverseBST(TreeNode* root) {
        string pre_order = "#";
        if (!root)
            return "";
        pre_order += traverseBST(root->left);
        pre_order += to_string(root -> val) + ",";
        pre_order += traverseBST(root->right);
        return pre_order;
    }
    string traverse_BST(TreeNode* root) {
        string pre_order = "#";
        if (!root)
            return "";
        pre_order += traverse_BST(root->right);
        pre_order += to_string(root -> val) + ",";
        pre_order += traverse_BST(root->left);
        return pre_order;
    }
    bool are_symmetric(TreeNode*r1, TreeNode*r2) {
        if (!r1 && !r2)
            return true;
        if ((!r1 && r2) || (r1 && !r2))
            return false;
        if (r1->val != r2->val)
            return false;
        return are_symmetric(r1->left, r2->right) && are_symmetric(r1->right, r2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return are_symmetric(root->left, root->right);  
    }
    bool is_Symmetric1(TreeNode* root) {
        if (!root)
            return true;
        string left_tree = traverseBST(root -> left);
        string right_tree = traverse_BST(root -> right);
        cout << left_tree << endl << right_tree << endl;
        return (left_tree == right_tree);
    }
    bool isSymmetric_iterative(TreeNode* root) {
        if(!root)
            return true;
        
        queue <TreeNode*> BST_ele;
        
        BST_ele.push(root->left);
        BST_ele.push(root->right);
        
        while(!BST_ele.empty()) {
            
            TreeNode* l = BST_ele.front();  BST_ele.pop();
            TreeNode* r = BST_ele.front();  BST_ele.pop();
            
            if((!l && r) || (l && !r)) 
                return false;
            
            if (l) {
                if(l->val != r->val)
                    return false;
            BST_ele.push(l->left); BST_ele.push(r->right); 
            BST_ele.push(l->right); BST_ele.push(r->left); 
            }
            
        }
        return true;
    }
};
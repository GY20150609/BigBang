//
// Created by yu2.guo on 2019/7/1.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#endif //LEETCODE_SOLUTION_H

#include <iostream>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int value):val(value),left(NULL),right(NULL){};
};

class Solution{
public:
    void displayTree(Node Head){
        int nums = 0;
        Node prev1(-1);
        Node prev2(-1);
        Node ptr = Head;
        while(ptr.left!=NULL || ptr.right!=NULL){
            if(nums==0){
                cout << ptr.val << endl;
                prev1 = ptr;
                prev2 = ptr;
            }
            if(nums%2==0){
                cout << prev2.right->left->val << endl;
                cout << prev2.right->right->val << endl;
                prev2 = *prev2.right;
            }
            else{
                cout << prev1.left->left->val << endl;
                cout << prev1.left->right->val << endl;
                prev1 = *prev1.left;
            }
            nums++;
        }
    };
};

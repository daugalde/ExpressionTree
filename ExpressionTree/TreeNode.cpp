#pragma once
#include <iostream>
#include "TreeNode.h"

TreeNode::TreeNode() {
    this->info = "";
    this->left = NULL;
    this->right = NULL;
}
TreeNode::TreeNode(string info) {
    this->info = info;
    this->left = NULL;
    this->right = NULL;
}
void TreeNode::SetInfo(string info) {
    this->info = info;
}
string TreeNode::GetInfo() {
    return this->info;
}

void TreeNode::SetLeft(TreeNode* left) {
    this->left = left;
}


TreeNode* TreeNode::GetLeft() {
    return left;
}


void TreeNode::SetRight(TreeNode* right) {
    this->right = right;
}


TreeNode* TreeNode::GetRight() {
    return right;
}

//bool TreeNode::equals(TInfo*& toCompare) {
//    return FALSE;
//}

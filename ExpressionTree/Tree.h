#pragma once
#include "TreeNode.h"
#include "Stack.h"

class Tree {

private:
    Stack* top;

public:

    Tree() { this->top = NULL; };

    void Push(TreeNode* node);

    TreeNode* Pop();

    TreeNode* Peek();

    bool IsEmpty() {
        return top != NULL;
    };

    void Display() {
        this->top->Display();
    }
};
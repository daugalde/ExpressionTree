#include "Tree.h"

void Tree::Push(TreeNode* node) {
    if (top == NULL)
        top = new Stack(node);
    else
    {
        Stack* nptr = new Stack(node);
        nptr->next = top;
        top = nptr;
    }
}

TreeNode* Tree::Pop()
{
    TreeNode* ptr = top->treeNode;
    top = top->next;
    return ptr;
}

TreeNode* Tree::Peek()
{
    return top->treeNode;
}
#pragma once
#include <string>
using namespace std;

class TreeNode {

private:

    string info;
    TreeNode* left;
    TreeNode* right;

public:

    TreeNode();
    TreeNode(string);
    void SetInfo(string);
    string GetInfo();
    void SetLeft(TreeNode*);
    TreeNode* GetLeft();
    void SetRight(TreeNode*);
    TreeNode* GetRight();
    //bool equals(TInfo*&);

};

typedef TreeNode* PointerTreeNode; //Alias

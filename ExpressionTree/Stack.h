#pragma once
#include <iostream>
#include <string>
#include "TreeNode.h"
#include "List.h"

using namespace std;

class Stack : public List {


public:

	Stack* next;

	Stack() {
		next = NULL;
	}

	Stack(TreeNode* node) {
		this->treeNode = node;
		next = NULL;
	}
	int Length();
	bool IsEmpty() { return head == NULL; }
	void Push(string value); // Inserts lef to right
	string Pop(); // Extract from right LIFO
	void Display(); // Print Stack Values
	string GetTopInfo();
};
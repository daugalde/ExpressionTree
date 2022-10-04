#pragma once
#include "Node.h"
#include "TreeNode.h"

using namespace std;

class List {

private:
	

public:
	PointerNode head;
	PointerNode current;
	TreeNode* treeNode;

	List() {
		head = NULL;
		current = NULL;
		treeNode = NULL;
	}

	List(PointerNode head) {
		this->head = head;
		current = NULL;
		treeNode = NULL;
	}

	void Unshift(string value); // Insert at Beginning
	void Push(string element); // Insert at End
	void Splice(string v, int pos); // Insert at Index Position
	bool IsEmpty() { return head == NULL; }
	bool IsStackEmpty() { return treeNode == NULL; }
	void Display();
	string DisplayFirstElementInfo();
	void Next();
	void First();
	void Last();
	string Pop();
	PointerTreeNode PopElement();
	void Shift();
	void RemoveAtIndex(int pos);
	int Length();

	friend class StaticQueue;
	friend class Stack;

};
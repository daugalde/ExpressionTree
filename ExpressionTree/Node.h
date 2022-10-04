#pragma once
#include <iostream>
#include <string>
#include "TreeNode.h"
class Node {

private:
	string element;
	Node* NextNode;


public:  // Constructors

	Node() {
		element = "";
		NextNode = NULL;
	}

	Node(string element)
	{
		this->element = element;
		NextNode = NULL;
	}

	Node(string element, Node* newNextNode)
	{
		this->element = element;
		NextNode = newNextNode;
	}

	friend class Stack;
	friend class StaticQueue;
	friend class List;
	friend class FileLoader;
};

typedef Node* PointerNode; //Alias

#pragma once
#include "List.h"
#include "Stack.h"
#include "Tree.h"
using namespace std;

class ExpressionProcessor {

private:

	Tree operandStack;

	Stack operatorStack;

	List expressionList;

public:
	ExpressionProcessor() { }

	void ProcessFiles();

	void DisplayExpressionList();

	void ProcessInfixExpression(List list);

	void EvaluateExpression();

	int GetPriorityStack(string stringOperator);

	int GetPriorityElement(string stringOperator);

	bool CheckIfNumber(string elementOperator);

	bool CheckEndParenthesis(string elementOperator);

	bool CompareOperators(int stackOperator, int elementOperator);

	bool CompareEqualsOperators(int stackOperator, int elementOperator);

};
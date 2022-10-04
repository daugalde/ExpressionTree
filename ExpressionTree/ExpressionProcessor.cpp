#include "List.h"
#include "FileLoader.h"
#include "ExpressionProcessor.h"
#include "Tree.h"
#include "Stack.h"
using namespace std;

void ExpressionProcessor::ProcessFiles() {

	FileLoader loader;

	int count = loader.LoadFiles();

	for (int i = 0; i < 5; i++)
	{
		cout << "START Display Expression List " + to_string(i + 1) << endl;
		ProcessInfixExpression(loader.GetListToProcess());
		cout << "END Display Expression List file " + to_string(i + 1) << endl;

		cout << "     " << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "     " << endl;

	}

}

void ExpressionProcessor::DisplayExpressionList() {
	//expressionList.DisplayString();
}

void ExpressionProcessor::ProcessInfixExpression(List list) {
	int length = list.Length();

	for (int i = 0; i < length; i++) {
		string element = list.Pop();

		if (CheckIfNumber(element)) {
			cout << "Adding Number  " << element << "\n" << endl;
			operandStack.Push(new TreeNode (element));
		}
		else if (GetPriorityStack(operatorStack.GetTopInfo()) < GetPriorityElement(element))
		{
			cout << "Adding Operator  " << element << "\n" << endl;
			operatorStack.Push(element);
		}
		else if (GetPriorityStack(operatorStack.GetTopInfo()) >= GetPriorityElement(element)) {
			string popedOut = "";
			do {
				popedOut = operatorStack.Pop();
				if (popedOut != "(" && popedOut != "")
				{
					cout << "Popping out element and build Tree " << element << "\n" << endl;
					TreeNode* newNode = new TreeNode(popedOut);
					newNode->SetRight(operandStack.Pop());
					newNode->SetLeft(operandStack.Pop());
					
					operandStack.Push(newNode);
				}

			} while ( popedOut != "");
		}
		
	}
	
}

int ExpressionProcessor::GetPriorityStack(string stringOperator) {
	if (stringOperator == "(") {
		return 0;
	}
	else if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 3;
	}
	else {
		return -1;
	}
}

int ExpressionProcessor::GetPriorityElement(string stringOperator) {
	if (stringOperator == "+" || stringOperator == "-") {
		return 1;
	}
	else if (stringOperator == "*" || stringOperator == "/") {
		return 2;
	}
	else if (stringOperator == "^") {
		return 4;
	}
	else if (stringOperator == "(") {
		return 5;
	}
	else {
		return -1;
	}
}

bool ExpressionProcessor::CheckIfNumber(string elementOperator) {

	try {
		int num = stoi(elementOperator);
		return true;
	}
	catch (std::exception& e) {
		return false;
	}
}

bool ExpressionProcessor::CheckEndParenthesis(string elementOperator)
{
	return elementOperator == ")";
}

bool ExpressionProcessor::CompareOperators(int stackOperator, int elementOperator) {
	return elementOperator < stackOperator;
}

bool ExpressionProcessor::CompareEqualsOperators(int stackOperator, int elementOperator) {
	return elementOperator >= stackOperator;
}

void ExpressionProcessor::EvaluateExpression() {

	int length = expressionList.Length();

	int num1 = NULL;

	int num2 = NULL;

	int result = 0;

	for (int i = 0; i <= length; i++) {
		string element = expressionList.PopElement()->GetInfo();

		if (CheckIfNumber(element) && num1 == NULL)
		{
			num1 = stoi(element);
			continue;
		}

		if (CheckIfNumber(element) && num2 == NULL)
		{
			num2 = stoi(element);
			continue;
		}

		if (element == "+") {
			result +=  num1 + num2;
		}
		else if (element == "-") {
			result += num1 - num2;
		}
		else if (element == "*") {
			result += num1 * num2;
		}
		else if (element == "/" && num2 != 0) {
			result += num1 / num2;
		}
		else if (element == "^") {
			
			while (num1 != 0) {
				result *= num1;
				--num1;
			}
			
		}

		num1 = NULL;

		num2 = NULL;
	}
	cout << "Evaluated Expression List " + to_string(result) << endl;
}
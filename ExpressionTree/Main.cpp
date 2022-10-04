#include <iostream>
#include <fstream>
#include "Node.h"
#include "StaticQueue.h"
#include "List.h"
#include "ExpressionProcessor.h"

using namespace std;

int main() {

	/// <summary>
	/// Process Files
	/// </summary>
	/// <returns></returns>
	ExpressionProcessor processor;

	processor.ProcessFiles();

	cin.get();

	return 0;
};

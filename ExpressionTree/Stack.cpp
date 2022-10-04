#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;

int Stack::Length() {
	return List::Length();
}

string Stack::GetTopInfo() {
	return List::DisplayFirstElementInfo();
};

void Stack::Push(string value) {
	
	List::Unshift(value);
};

string Stack::Pop() {
	return List::Pop();
};

void Stack::Display() {
	List::Display();
};


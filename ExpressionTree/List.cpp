#include "Node.h"
#include "List.h"

using namespace std;

int List::Length() {
	int cont = 0;

	PointerNode aux = head;
	if (IsEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
		cout << endl;
	}

}

void List::Unshift(string value)
{
	if (IsEmpty())
	{
		head = new Node(value);
	}
	else
	{
		head = new Node(value, head);
	}
}

void List::Push(string element)
{
	if (IsEmpty()) {
		head = new Node(element);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(element);
	}
}

void List::Splice(string v, int pos)
{
	if (IsEmpty()) {
		head = new Node(v);
	}
	else {
		if (pos <= 1)
		{
			Unshift(v);
		}
		else {
			Node* aux = head;
			int i = 2;
			while ((i != pos) && (aux->NextNode != NULL)) {
				i++;
				aux = aux->NextNode;
			}
			PointerNode newNodeFirst = new Node(v);
			newNodeFirst->NextNode = aux->NextNode;
			aux->NextNode = newNodeFirst;
		}
	}
}

string List::Pop()
{
	string result = "";
	if (!IsEmpty()) {

		if (head != NULL)
		{
			PointerNode temp = head;
			result = head->element;
			head = head->NextNode;
			delete temp;
		}
	}
	return result;
}

PointerTreeNode List::PopElement()
{
	PointerTreeNode result = NULL;
	if (!IsEmpty()) {

		if (head != NULL)
		{
			PointerNode temp = head;
			//result = head->;
			head = head->NextNode;
			delete temp;
		}
	}
	return result;
}

void List::Shift()
{
	if (IsEmpty()) {
		cout << "Empty List:" << endl;
	}
	else {
		if (head->NextNode == NULL)
		{
			PointerNode temp = head;
			head = NULL;
			delete temp;
		}
		else
		{
			PointerNode aux = head;
			head = head->NextNode;
			delete aux;
		}
	}
}

void List::RemoveAtIndex(int index) {
	if (IsEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		if ((index > Length()) || (index < 0)) {
			cout << "An Index should be greater than zero" << endl;
		}
		else {
			if (index == 1)
			{
				PointerNode temp = head;
				head = head->NextNode;
				delete temp;
			}
			else {
				int cont = 2;
				PointerNode aux = head;
				while (cont < index) {
					aux = aux->NextNode;
					cont++;
				}
				PointerNode temp = aux->NextNode;
				aux->NextNode = aux->NextNode->NextNode;
				delete temp;
			}
		}
	}
}

void List::Display()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty Here";
	}
	else
	{
		aux = head;
		while (aux)
		{
			cout << aux->element << endl;
			aux = aux->NextNode;
		}
		cout << endl;
	}
}

string List::DisplayFirstElementInfo()
{
	if (head == NULL) {
		return "";
	}
	else {
		Node* aux;

		aux = head;

		return aux->element;
	}
}

void List::Next()
{
	if (current) current = current->NextNode;
}

void List::First()
{
	current = head;
}

void List::Last()
{
	current = head;
	if (!IsEmpty())
		while (current->NextNode) Next();
}
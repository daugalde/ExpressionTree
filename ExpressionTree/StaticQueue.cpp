#include <iostream>
#include "StaticQueue.h"
using namespace std;

bool StaticQueue::IsEmpty()
{
    return this->back < this->front;
}

void StaticQueue::Push(PointerNode node)
{
    if (back < 5 - 1) {
        ++back;
        StaticQueueArray[back] = node;

    }
    else {
        cout << "La cola esta llena";
    }
}

PointerNode StaticQueue::Pop()
{
    if (!IsEmpty()) {
        front++;
        return StaticQueueArray[front - 1];
    }
    else {
        cout << "La cola esta vacia";
    }
}

void StaticQueue::Display() {
    for (int i = front; i < back + 1; i++) {
       // cout << StaticQueueArray[i] << "->" << endl;
    }

    if (IsEmpty()) {
        cout << "La cola esta vacia";
    }
}

